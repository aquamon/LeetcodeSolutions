class Solution {
public:

    bool check(int start,vector<int>&gas,vector<int>&cost)
    {
        int curr_gas = gas[start];

        int next_station = (start+1)%gas.size();

        int count = 0;
        while(curr_gas >= cost[start])
        {
            curr_gas -= cost[start];
            curr_gas += gas[next_station];
            start = next_station;
            next_station = (next_station+1)%gas.size();
            count++;
            if(count >= gas.size())
                return true;

        }
        
        return false;
    }
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        // vector<int>start;

        // for(int i=0;i<gas.size();i++)
        // {
        //     if(cost[i] <= gas[i])
        //         start.push_back(i);
        // }

        // if(start.size() < 1)
        //     return -1;
        
        // for(int i=0;i<start.size();i++)
        // {
        //     if(check(start[i],gas,cost))
        //         return start[i];
        // }
        // return -1;

        int start = 0, tank = 0, deficit = 0;

        for(int i=0;i<gas.size();i++)
        {
            tank += gas[i] - cost[i];
            if(tank < 0)
            {
                start = i+1;
                deficit += tank;
                tank = 0;
            }
        }
        if(tank + deficit >= 0)
            return start;
        return -1;
    }
};