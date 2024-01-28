class Solution {
public:
  
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

         for(int r1=0;r1<M;r1++)
        {
            for(int r2 = r1;r2<M;r2++)
            {
                unordered_map<int,int>subMatrixSum;

                subMatrixSum[0] = 1;

                for(int c2 = 0;c2 < N; c2++)
                {
                    int up = r1-1 >= 0 ? matrix[r1-1][c2] : 0;
                    int current_sum = matrix[r2][c2] - up;

                    int other = current_sum - k;

                    ans += subMatrixSum[other];

                    subMatrixSum[current_sum]++;


                }
            }
        }

        return ans;


        
    }
};