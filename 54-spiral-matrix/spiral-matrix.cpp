class Solution {
public:

    void print(vector<vector<int>>&mat,int row, int col,int R,int C,vector<int>&res)
    {
        if(row >= R or col >= C)
            return;
        
        for(int i=row;i<C;i++)
            res.push_back(mat[row][i]);
        
        for(int i=row+1;i<R;i++)
            res.push_back(mat[i][C-1]);
        
        if(R-1 != row)
        {
             for(int i=C-2;i>=col;i--)
            {
                res.push_back(mat[R-1][i]);
            }

        }
        if(C-1 != col)
        {
            for(int i=R-2;i>row;i--)
            {
                res.push_back(mat[i][col]);
            }

        }
        print(mat,row+1,col+1,R-1,C-1,res);
        
        
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        int M = matrix.size();
        int N = matrix[0].size();

        vector<int>res;
        if(matrix.size() == 0)
        {
            vector<int>A;
            return A;
        }
        print(matrix,0,0,M,N,res);

        return res;
    }
};