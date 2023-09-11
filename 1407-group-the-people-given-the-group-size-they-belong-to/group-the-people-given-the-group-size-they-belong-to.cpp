class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        
        unordered_map<int,vector<int>>M;

        for(int i=0;i<groupSizes.size();i++)
        {
            M[groupSizes[i]].push_back(i);
        }

        vector<vector<int>>ans;

        for(auto it:M)
        {
            int X = it.first;
            int sz = it.second.size();
            vector<int> A = it.second;
            if(sz <= X)
                ans.push_back(it.second);
            else
            {
                vector<int>temp;
                int curr_size = 0;
                for(int i=0;i<sz;i++)
                {
                    if(curr_size++ < X)
                        temp.push_back(A[i]);
                    else
                    {
                        ans.push_back(temp);
                        temp.clear();
                        temp.push_back(A[i]);
                        curr_size = 1;
                    }
                }
                if(curr_size >= 1)
                    ans.push_back(temp);
                
            }
        }
        

        return ans;
    
    }
};