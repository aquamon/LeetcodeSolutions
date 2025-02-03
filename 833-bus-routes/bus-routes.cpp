class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        
        if(source == target)
        {
            return 0;
        }

        unordered_map<int,vector<int>> adjList;

        for(int route = 0;route < routes.size();route++)
        {
            for(auto stop : routes[route])
            {
                adjList[stop].push_back(route);
            }
        }

       queue<int>Q;
       unordered_set<int>vis;

       
        for(auto route : adjList[source])
        {
           Q.push(route);
           vis.insert(route);
        }

        int busCount = 1;

        while(Q.size())
        {
            int size = Q.size();

            while(size--)
            {
                int route = Q.front();
                Q.pop(); 

                for(auto stop : routes[route])
                {
                    if(stop == target)
                    {
                        return busCount;
                    }

                    for(auto nextRoute : adjList[stop])
                    {
                        if(!vis.count(nextRoute))
                        {
                            vis.insert(nextRoute);
                            Q.push(nextRoute);

                        }
                    }
                }    
            }
            busCount++;
        }
      
      return -1;
    }
};