class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        
        int N = mat.size() , M = mat[0].size();

        for(int i=0;i<N;i++)
        {
            for(int j=1;j<M;j++)
            {
                mat[i][j] += mat[i][j-1];
            }
        }

        for(int i=0;i<M;i++)
        {
            for(int j=1;j<N;j++)
            {
                mat[j][i] += mat[j-1][i];
            }
        }

        vector<vector<int>>ans(N,vector<int>(M,0));
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
            {
                int topX = i-k , topY = j-k;
                int botX = i+k , botY = j+k;
                topX = max(0,topX);
                topY = max(0,topY);
                botX = min(botX,N-1);
                botY = min(botY,M-1);

                ans[i][j] = mat[botX][botY];
                if(topX > 0)
                    ans[i][j] -= mat[topX-1][botY];
                if(topY > 0)
                    ans[i][j] -= mat[botX][topY-1];
                if(topX > 0 and topY > 0)
                    ans[i][j] += mat[topX-1][topY-1];
            }
        }

        return ans;
    }
};