class Solution {
public:

    void print(int x1, int y1, int x2, int y2,vector<vector<int>>&mat,vector<int>&res)
    {
        for(int i=y1;i<=y2;i++)
            res.push_back(mat[x1][i]);
        
        for(int j=x1+1;j<x2;j++)
            res.push_back(mat[j][y2]);
        
        for(int i=y2;i>=y1;i--)
            res.push_back(mat[x2][i]);
        
        for(int j=x2-1;j>x1;j--)
            res.push_back(mat[j][y1]);
        
        return;
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        int M = matrix.size();
        int N = matrix[0].size();

        int x1 = 0 , y1 = 0 , x2 = M-1, y2 = N-1;
        vector<int>res;
        while(x1 < x2 and y1 < y2)
        {
            print(x1,y1,x2,y2,matrix,res);
            x1++;
            x2--;
            y1++;
            y2--;
        }

        if(x1 == x2 and y1 == y2)
        {
            res.push_back(matrix[x1][y2]);

        }
        else if(x1 == x2 and y1 < y2)
        {
            for(int i=y1;i<=y2;i++)
                res.push_back(matrix[x1][i]);
        }

        else if(y1 == y2 and x1 < x2)
        {
            for(int j=x1;j<=x2;j++)
                res.push_back(matrix[j][y1]);
        }

        return res;


    }
};