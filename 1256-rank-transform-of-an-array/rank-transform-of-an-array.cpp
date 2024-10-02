class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        
        vector<int>res(arr.size());
        if(arr.size() < 1)
            return res;
        if(arr.size() == 1)
            return {1};
        
        vector<pair<int,int>>RES;
        for(int i=0;i<arr.size();i++)
        {
            RES.push_back({arr[i],i});
        }

        sort(RES.begin(),RES.end());
        res[RES[0].second] = 1;
        int curr_rank = 1;
        for(int i=1;i<RES.size();i++)
        {
            if(RES[i].first == RES[i-1].first)
            {
                res[RES[i].second] = curr_rank;
            }
            else
            {
                res[RES[i].second] = ++curr_rank;
            }

        }
        return res;
    }
};