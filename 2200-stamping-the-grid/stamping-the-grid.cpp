class Solution {
public:

    void compute(vector<vector<int>>& psum,int N,int M)
    {
        for(int i=0;i<N;i++)
        {
            for(int j = 1 ; j< M;j++)
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
    }
    int computePrefix(vector<vector<int>>& psum,int r1,int c1,int r2,int c2)
    {
        

        int ans = psum[r2][c2];

        if(r1-1 >=0 )
            ans -= psum[r1-1][c2];
        if(c1-1 >= 0)
            ans -= psum[r2][c1-1];
        
        if(r1-1 >= 0 and c1-1 >= 0)
            ans += psum[r1-1][c1-1];
        
        return ans;




    }
    bool possibleToStamp(vector<vector<int>>& grid, int stampHeight, int stampWidth) {
        
        vector<vector<int>> psum = grid;
        
        int N = grid.size() , M = grid[0].size();
        compute(psum,N,M);

        
        vector<vector<int>> B(N,vector<int>(M,0));

        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
            {
                int bottomX = i+stampHeight-1;
                int bottomY = j+stampWidth-1;

                if(bottomX < N and bottomY < M)
                {
                    int sum = computePrefix(psum,i,j,bottomX,bottomY);
                    if(sum == 0)
                    {
                        B[bottomX][bottomY] = 1;
                    }
                }



            }
        }

        compute(B,N,M);

        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
            {
                int X = i+stampHeight-1;
                int Y = j+stampWidth-1;

                int bottomX = min(X,N-1);
                int bottomY = min(Y,M-1);
                if(grid[i][j] == 0)
                {
                    int sum = computePrefix(B,i,j,bottomX,bottomY);
                    if(sum == 0)
                    {
                       return false;
                    }
                }



            }
        }
        return true;


    }
};