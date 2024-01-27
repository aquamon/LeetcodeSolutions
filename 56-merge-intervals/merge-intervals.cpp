class Solution {
public:
    static bool cmp(vector<int>&a , vector<int>&b)
    {
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;

        if(intervals.size() < 2)
            return intervals;
        
        sort(intervals.begin(),intervals.end(),cmp);
        
        vector<int>curr = intervals[0];
        for(int i=1;i<intervals.size();i++)
        {
            if(curr[1] >= intervals[i][0])
            {
                curr[1] = max(curr[1],intervals[i][1]);
            }
            else
            {
                res.push_back(curr);
                curr = intervals[i];
            }
        }

        res.push_back(curr);

        return res;
    }
};