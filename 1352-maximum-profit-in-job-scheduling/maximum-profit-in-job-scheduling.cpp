class Solution {
public:
    vector<int>DP;
    struct Job{
        int start,end,profit;
        Job(int a,int b,int c){
            start = a;
            end = b;
            profit = c;
        }
    };
    bool static cmp(Job &a, Job &b)
    {
        return a.end < b.end;
    }

    int solve(int idx,vector<Job>&task)
    {
        if(DP[idx] != -1)
            return DP[idx];
        
        int profit = task[idx].profit;
        int start = task[idx].start;
        int end = task[idx].end;

        if(idx == 0)
            return DP[idx] = profit;
        
        int take = profit;
        for(int i = idx-1;i>=0;i--)
        {
            if(task[i].end <= start)
            {
                take += solve(i,task);
                break;
            }
        }

        int not_take = solve(idx-1,task);

        return DP[idx] = max(take,not_take);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        
        vector<Job> task;

        for(int i=0;i<profit.size();i++)
        {
            task.push_back(Job(startTime[i],endTime[i],profit[i]));
        }

        sort(task.begin(),task.end(),cmp);

        DP.assign(task.size(),-1);

        return solve(task.size()-1,task);
        

    }
};