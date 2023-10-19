class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        
        vector<vector<int>>graph(n,vector<int>());
        vector<int>Indegree(n,0);
        for(int i=0;i<relations.size();i++)
        {
            int u = relations[i][0]-1;
            int v = relations[i][1]-1;

            graph[u].push_back(v);

            Indegree[v]++;

        }

        queue<int>Q;
        vector<int>maxTime(n,0);
        for(int i=0;i<n;i++)
        {
            if(Indegree[i] == 0)
            {
                Q.push(i);
                maxTime[i] = time[i];

            }
        }

        while(!Q.empty())
        {
            int node = Q.front();
            Q.pop();

            for(int neighbour : graph[node])
            {
                Indegree[neighbour]--;
                maxTime[neighbour] = max(maxTime[neighbour] , maxTime[node] + time[neighbour]);
                if(Indegree[neighbour] == 0)
                    Q.push(neighbour);
            }
        }

        return *max_element(maxTime.begin(),maxTime.end());
    }
};