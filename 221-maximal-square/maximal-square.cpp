class Solution {
public:
    vector<vector<int>> compute(vector<vector<char>>&matrix,int N,int M)
    {
        vector<vector<int>>psum(N,vector<int>(M,0));
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
            {
                if(matrix[i][j] == '1')
                {
                    psum[i][j] = 1;
                }
                
            }
        }
        for(int i=0;i<N;i++)
        {
            for(int j=1;j<M;j++)
            {
                psum[i][j] += psum[i][j-1];
            }
        }

        for(int j=0;j<M;j++)
        {
            for(int i=1;i<N;i++)
            {
                psum[i][j] += psum[i-1][j];
            }
        }
        return psum;
    }
    int giveSum(vector<vector<int>>&matrix,int r1,int c1,int r2,int c2)
    {
        int ans = matrix[r2][c2];
        
        if(r1 > 0)
            ans -= matrix[r1-1][c2];
        if(c1 > 0)
            ans -= matrix[r2][c1-1];
        if(r1 > 0 and c1 > 0)
            ans += matrix[r1-1][c1-1];
        return ans;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        
        int N = matrix.size();
        int M = matrix[0].size();

        vector<vector<int>>psum(N,vector<int>(M,0));
        psum = compute(matrix,N,M);

        

        int ans = 0;
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
            {
                if(matrix[i][j] == '1')
                {
                    ans = max(ans,1);

                    int botX = max(i,N-1);
                    int botY = max(j,M-1);

                    int curr_row = i+1 , curr_col = j+1;
                    
                    while(curr_row <= botX and curr_col <= botY)
                    {
                        int sum = giveSum(psum,i,j,curr_row,curr_col);

                        int dist = curr_row-i+1;
                        if(dist*dist == sum)
                            ans = max(ans,sum);

                        curr_row++;
                        curr_col++;    
                    }
                }
            }
        }

        return ans;
    }
};