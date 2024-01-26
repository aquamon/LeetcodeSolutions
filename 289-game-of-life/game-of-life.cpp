class Solution {
public:
    bool isSafe(int x,int y,vector<vector<int>>&board)
    {
        int ROW = board.size();
        int COL = board[0].size();

        return x >= 0 and x < ROW and y >=0 and y < COL;
    }
    int CountNeighbour(vector<vector<int>>&board,int i,int j)
    {
        int R = board.size();
        int C = board[0].size();

        int X[] = {1,1,0,-1,-1,-1,0,1};
        int Y[] = {0,1,1,1,0,-1,-1,-1};

        int count = 0;

        for(int k=0;k<8;k++)
        {
            if(isSafe(i+X[k],j+Y[k],board) and (board[i+X[k]][j+Y[k]] == 1 or board[i+X[k]][j+Y[k]] == 2))
                count++;
        }
        return count;
    }
    void gameOfLife(vector<vector<int>>& board) {

       for(int i=0;i<board.size();i++)
       {
           for(int j=0;j<board[0].size();j++)
           {
               int countNeighbour = CountNeighbour(board,i,j);

               if(board[i][j] == 0)
               {
                   if(countNeighbour == 3)
                   {
                       board[i][j] = 3;
                   }
               }
               else
               {
                   if(countNeighbour < 2)
                   {
                       board[i][j] = 2;
                   }
                   else if(countNeighbour == 2 or countNeighbour == 3)
                   {
                       continue;
                   }
                   else if(countNeighbour  > 3)
                   {
                       board[i][j] = 2;
                   }
                   else
                   {
                       continue;
                   }
               }
           }
       } 

       for(int i=0;i<board.size();i++)
       {
           for(int j=0;j<board[0].size();j++)
           {
               if(board[i][j] == 2)
                board[i][j] = 0;
                else if(board[i][j] == 3)
                    board[i][j] = 1;
           }
       }
    }
};