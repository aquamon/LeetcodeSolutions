class Solution {
public:

    int solve(int x, int y, vector<vector<int>>&matrix,vector<vector<int>>&DP)
    {
       if(x >= matrix.size() or y >= matrix.size() or y < 0 or x < 0)
        return 0;
    
        if(DP[x][y] != INT_MAX)
            return DP[x][y];
        
        
        int a = INT_MAX , b = INT_MAX;
        if(y > 0)
            a = solve(x+1,y-1,matrix,DP);
        if(y < matrix.size()-1)
            b = solve(x+1,y+1,matrix,DP);
        int c = solve(x+1,y,matrix,DP);

        DP[x][y] =  min({a,b,c})+matrix[x][y];

        return DP[x][y];
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int n = matrix.size();

        int ans = INT_MAX;
        vector<vector<int>>DP(n,vector<int>(n,INT_MAX));
        for(int i=0;i<matrix.size();i++)
        {

            ans = min(ans,solve(0,i,matrix,DP));
        }
        return ans;
         
    }
};