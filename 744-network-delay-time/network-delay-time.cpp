class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<pair<int,int>>adj[n+1];

        for(auto it:times)
        {
            adj[it[0]].push_back({it[1] , it[2]});
        }

        vector<int>distance(n+1,INT_MAX);

        distance[k] = 0;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>PQ;

        PQ.push({0,k});

        while(!PQ.empty())
        {
            pair<int,int> curr = PQ.top();
            int node = curr.second;
            int wt = curr.first;
            PQ.pop();
            for(auto it:adj[node])
            {
                int adjNode = it.first;
                int adjWt = it.second;

                if(wt + adjWt < distance[adjNode])
                {
                    distance[adjNode] = wt + adjWt;
                    PQ.push({wt+adjWt , adjNode});
                }
            }
        }
        int ans = INT_MIN;
        for(int i=1;i<distance.size();i++)
        {
            if(distance[i] == INT_MAX)
                return -1;
            ans = max(ans,distance[i]);
        }

        return ans;

    }
};