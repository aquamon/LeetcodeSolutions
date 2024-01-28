class Solution {
public:
  int sum(int r1, int c1, int r2 ,int c2, int M, int N,vector<vector<int>>& matrix)
    {
        int A = matrix[r2][c2];
        int B = 0, C=0, D=0;

        if(r1-1 >= 0)
            B = matrix[r1-1][c2];
        
        if(c1-1 >= 0)
            C = matrix[r2][c1-1];
        
        if(r1-1 >= 0 and c1-1>=0)
            D = matrix[r1-1][c1-1];
        

        return A-B-C+D;
    }
    int solve(int r1, int c1, vector<vector<int>>& matrix, int target,int M, int N)
    {
        int ans = 0;
        for(int i=r1; i < M; i++)
        {
            for(int j=c1; j<N;j++)
            {
               
                
                
                int r2 = i, c2 = j;

                if(sum(r1,c1,r2,c2,M,N,matrix) == target)
                    ans++;
            }
        }
        return ans;
    }
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int k) {
         int M = matrix.size();
        int N = matrix[0].size();
        int ans = 0;
        for(int i=0;i<M;i++)
        {
            for(int j=1;j<N;j++)
            {
                matrix[i][j] += matrix[i][j-1];
            }
        }

        for(int j=0;j<N;j++)
        {
            for(int i=1;i<M;i++)
            {
                matrix[i][j] += matrix[i-1][j];
            }
        }

        for(int i=0;i<M;i++)
        {
            for(int j=0;j<N;j++)
            {
                int r1 = i, c1 = j;
                ans += solve(r1,c1,matrix,k,M,N);
            }
        }
        return ans;
    }
};