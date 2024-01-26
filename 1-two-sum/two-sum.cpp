class Solution {
public:
    
    static bool cmp(pair<int,int>&P1,pair<int,int>&P2)
    {
        return P1.second < P2.second;
    }
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<pair<int,int>>VEC;

        int i=0;
        for(int x:nums)
        {
            VEC.push_back({i++,x});
        }

        sort(VEC.begin(),VEC.end(),cmp);

        int  j=nums.size()-1;
        i=0;
        while(i<j)
        {
            int curr_sum = VEC[i].second + VEC[j].second;

            if(curr_sum == target)
            {
                return {VEC[i].first,VEC[j].first};
            }
            else if(curr_sum > target)
            {
                j--;
            }
            else
            {
                i++;
            }
        }
        return {};
    }
};