class Solution {
public:

    bool isSafe(int i,int j, int M,int N)
    {
        return i>=0 and i<M and j>=0 and j<N;
    }

    
    bool solve(int i, int j,int M, int N,vector<vector<char>> &board,string word,int idx)
    {
       
        if(idx == word.size())
        {
            return true;
        }

        if(isSafe(i,j,M,N) and board[i][j] == word[idx])
        {
            int X[] = {1,0,-1,0};
            int Y[] = {0,1,0,-1};
            char temp = board[i][j];
            board[i][j] = '0';
            bool res = false;
            for(int curr = 0; curr < 4 ; curr++)
            {
                
                int x = X[curr] + i;
                int y = Y[curr] + j;

                res = res or solve(x,y,M,N,board,word,idx+1);
            }
            board[i][j] = temp;
            return res;

        } 
        return false;


    }
    bool exist(vector<vector<char>>& board, string word) {
        
        int M = board.size();
        int N = board[0].size();
        
        for(int i=0;i<M;i++)
        {
            for(int j=0;j<N;j++)
            {
                if(board[i][j] == word[0])
                {
                    if(solve(i,j,M,N,board,word,0))
                        return true;
                }
            }
        }
        return false;
    }
};