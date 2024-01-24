class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        vector<unordered_map<int,int>>ROW(9);
        vector<unordered_map<int,int>>COL(9);
        vector<unordered_map<int,int>>BOX(9);

        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j] == '.')
                    continue;
                int curr = board[i][j] - '0';
                
                if(ROW[i].find(curr) != ROW[i].end())
                    return false;
                if(COL[j].find(curr) != COL[i].end())
                    return false;
                int box = (i/3) + (j/3) + ((i/3)*2);
                if(BOX[box].find(curr) != BOX[box].end())
                    return false;
                
                ROW[i][curr]++;
                COL[j][curr]++;
                BOX[box][curr]++;


            }
        }
        return true;
    }
};