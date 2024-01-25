class Solution {
public:
    void makeZeroRow(int row,vector<vector<int>>&matrix)
    {
        for(int i=0;i<matrix[0].size();i++)
            matrix[row][i] = 0;
    }
     void makeZeroCol(int col,vector<vector<int>>&matrix)
    {
        for(int i=0;i<matrix.size();i++)
            matrix[i][col] = 0;
    }
    void setZeroes(vector<vector<int>>& matrix) {
        
        
        bool firstRowZero = false;
        bool firstColZero = false;

        for(int j=0;j<matrix[0].size();j++)
        {
            if(matrix[0][j] == 0)
            {
                firstRowZero = true;
                break;
            }
        }
        for(int j=0;j<matrix.size();j++)
        {
            if(matrix[j][0] == 0)
            {
                firstColZero = true;
                break;
            }
        }

        for(int i=1;i<matrix.size();i++)
        {
            for(int j=1;j<matrix[0].size();j++)
            {
                if(matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for(int j=1;j<matrix[0].size();j++)
        {
            if(matrix[0][j] == 0)
            {
                makeZeroCol(j,matrix);
            }
        }
        for(int i=1;i<matrix.size();i++)
        {
            if(matrix[i][0] == 0)
            {
                makeZeroRow(i,matrix);

            }
        }

        if(firstRowZero)
            for(int i=0;i<matrix[0].size();i++)
                matrix[0][i] = 0;
        
        if(firstColZero)
        {
            for(int i=0;i<matrix.size();i++)
                matrix[i][0] = 0;
        }
       


    }
};