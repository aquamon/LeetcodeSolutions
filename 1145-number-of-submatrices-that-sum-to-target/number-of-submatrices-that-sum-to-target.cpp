class Solution {

private:
    int m,n;
    vector<vector<int>>sum;

    void calculateSum(vector<vector<int>>&matrix){

        sum.clear();
        sum.resize(this->m,vector<int>(this->n,0));    
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int up , left, up_left;
                up = i-1 >= 0 ? sum[i-1][j] : 0;
                left = j-1>=0 ? sum[i][j-1] : 0;
                up_left = i-1 >=0 and j-1 >=0 ? sum[i-1][j-1] : 0;

                sum[i][j] = up + left - up_left + matrix[i][j];


            }
        }           
    }

public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        
        this->m = matrix.size();
        this->n = matrix[0].size();

        calculateSum(matrix);

        int result = 0;
        int temp;
        for(int r1 = 0 ; r1 < this->m ; r1++)
        {
            for(int r2 = r1 ; r2 < this->m ; r2++)
            {
                unordered_map<int,int>M;
                M[0]++;

                int up,current_sum,other;
                for(int c2 = 0 ; c2 < this-> n ; c2++)
                {
                    up = r1-1 >= 0 ? sum[r1-1][c2] : 0;
                    current_sum = sum[r2][c2] - up;

                    other = current_sum - target;

                    result += M[other];
                    
                    M[current_sum]++;

                }
            }
        }

        return result;

    }

    
};