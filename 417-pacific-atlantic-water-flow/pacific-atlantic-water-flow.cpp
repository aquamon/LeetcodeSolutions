class Solution {
public:
    int N,M;
    vector<vector<bool>> pacific;
    vector<vector<bool>> atlantic;
    vector<vector<int>>ans;

    void dfs(vector<vector<int>> &heights, vector<vector<bool>>&isVis,int i,int j)
    {
        if(isVis[i][j])
            return;
        
        isVis[i][j] = true;
        
        if(pacific[i][j] and atlantic[i][j])
            ans.push_back({i,j});
        
        

        if(i+1 < heights.size() and heights[i+1][j] >= heights[i][j])
        {
            dfs(heights,isVis,i+1,j);
        }
        if(i-1 >= 0 and heights[i-1][j] >= heights[i][j])
        {
            dfs(heights,isVis,i-1,j);
        }
        if(j+1 < heights[0].size() and heights[i][j+1] >= heights[i][j])
        {
            dfs(heights,isVis,i,j+1);
        }
        if(j-1 >= 0 and heights[i][j-1] >= heights[i][j])
        {
            dfs(heights,isVis,i,j-1);
        }


    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        N = heights.size();
        M = heights[0].size();
        pacific = atlantic = vector<vector<bool>>(N,vector<bool>(M,false));
        for(int i=0;i<M;i++)
        {
            dfs(heights,pacific,0,i);
            dfs(heights,atlantic,N-1,i);
        }
        for(int i=0 ; i < N ; i++)
        {
            dfs(heights,pacific,i,0);
            dfs(heights,atlantic,i,M-1);
        }
        return ans;
    }
};