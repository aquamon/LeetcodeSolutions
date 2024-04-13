class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.size() == 1)
            return heights[0];
        
        vector<int>pre_smaller(heights.size());
        vector<int>next_smaller(heights.size());

        stack<int>S;
        S.push(heights.size()-1);    
        for(int i=heights.size()-2;i>=0;i--)
        {
            while(!S.empty() && heights[i] < heights[S.top()])
            {
                pre_smaller[S.top()] = i;
                S.pop();
            }
            S.push(i);
        }
        while(!S.empty())
        {
            pre_smaller[S.top()] = -1;
            S.pop();
        }

        S.push(0);

        for(int i=1;i<heights.size();i++)
        {
            while(!S.empty() && heights[i] < heights[S.top()] )
            {
                next_smaller[S.top()] = i;
                S.pop();
            }
            S.push(i);
        }
        while(!S.empty())
        {
            next_smaller[S.top()] = heights.size();
            S.pop();
        }
        int ans = INT_MIN;
        for(int i=0;i<heights.size();i++)
        {
            // cout<<pre_smaller[i] <<" "<<next_smaller[i]<<endl;
            ans = max(ans,(next_smaller[i]-pre_smaller[i]-1)*heights[i]);
        }
        return ans;

    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int R = matrix.size();
        if(R < 1)
            return 0;
        int C = matrix[0].size();
        
        if(C < 0)
            return 0;
        
        vector<int>heights(C,0);
        int ans = 0;
        for(int i=0;i<R;i++)
        {
            for(int j=0;j<C;j++)
            {
                if(matrix[i][j] == '1')
                {
                    if(heights[j] > 0)
                        heights[j] += 1;
                    else
                        heights[j] = 1;
                }
                else
                {
                    heights[j] = 0;
                }
            }
            // for(auto i:heights)
            //     cout<<i<<" ";
            // cout<<endl;
            // cout<<AreaHistogram(heights)<<endl;
            ans = max(ans,largestRectangleArea(heights));
        }
        return ans;
    }
};