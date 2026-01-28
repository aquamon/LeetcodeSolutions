class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        
        int N = mat.size();
        int M = mat[0].size();

        int rotation_needed = k%M;

        if(rotation_needed == 0)
            return true;
        
        for(int i=0;i<N;i+=2)
        {
            for(int j=M-1;j>=0;j--)
            {
               int new_pos = (j-rotation_needed+M)%M;
               if(mat[i][j] != mat[i][new_pos])
                    return false;
            }
        }
        for(int i=1;i<N;i+=2)
        {
            for(int j=0;j<M;j++)
            {
                int new_pos = (j+rotation_needed)%M;
               if(mat[i][j] != mat[i][new_pos])
                    return false;
            }
            
        }

        return true;

    }
};