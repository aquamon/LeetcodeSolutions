class Solution {
public:
    void bfs(int S,vector<int> adj[] , vector<int>&vis)
    {
        if(vis[S] == true)
            return;
        vis[S] = true;
        
        for(auto it : adj[S])
        {
            bfs(it,adj,vis);
        }
        return;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        vector<int>adj[n];

        for(auto it:edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int>vis(n,false);

        bfs(source,adj,vis);

        return vis[destination];

        
    }
};