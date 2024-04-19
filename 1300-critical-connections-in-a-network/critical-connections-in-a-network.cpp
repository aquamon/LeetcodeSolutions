class Solution {
private:
    int timer = 1;

    void dfs(vector<int> adj[],int src,int parent,vector<bool>&isVis,vector<int>&time,vector<int>&low,vector<vector<int>>&ans)
    {
        if(isVis[src])
            return;
        
        isVis[src] = true;
        

        time[src] = timer;
        low[src] = timer;
        timer++;
        for(auto it:adj[src])
        {
           if(it == parent) continue;
           if(isVis[it] == false)
           {
                dfs(adj,it,src,isVis,time,low,ans);
                low[src] = min(low[src],low[it]);

                if(low[it] > time[src])
                {
                    ans.push_back({it,src});
                }
           }
           else
           {
                low[src] = min(low[it],low[src]);
           }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        vector<int>adj[n];

        for(auto it:connections)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        

        vector<bool> isVis(n,false);
        vector<int> time(n,0);
        vector<int>low(n,0);

        vector<vector<int>>ans;

        dfs(adj,0,-1,isVis,time,low,ans);

        return ans;
    }
};