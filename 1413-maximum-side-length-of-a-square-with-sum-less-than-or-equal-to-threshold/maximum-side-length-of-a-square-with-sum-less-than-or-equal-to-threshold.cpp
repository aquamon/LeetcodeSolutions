class Solution {
public:

    int getSum( vector<vector<int>>&prefix,int x1,int y1, int x2 , int y2)
    {
        return prefix[x2][y2]-prefix[x2][y1-1] - prefix[x1-1][y2]+prefix[x1-1][y1-1];
    }
    int maxSideLength(vector<vector<int>>& mat, int threshold)
    {
        
        int M = mat.size();
        int N = mat[0].size();
        vector<vector<int>> prefix(M+1,vector<int>(N+1));

        for(int i=1;i<=M;i++)
        {
            for(int j = 1 ; j<=N;j++)
            {
                prefix[i][j] = prefix[i][j-1] + prefix[i-1][j] - prefix[i-1][j-1] + mat[i-1][j-1];
            }
        }

        int ans = 0;

        int l = 1 , r = min(M,N);

        while(l<=r)
        {
            int mid = l +( (r-l)/2);

            bool find = false;

            for(int i=1;i<= M+1-mid;i++)
            {
                for(int j=1;j<= N+1-mid;j++)
                {
                   int sum = getSum(prefix,i,j,i+mid-1,j+mid-1);
                   if(sum <= threshold)
                   {
                    find = true;
                   } 
                } 
            }
            if(find)
            {
                ans = mid;
                l = mid+1;
            }
            else
            {
                r = mid-1;
            }
        }

        return ans;
    }
};