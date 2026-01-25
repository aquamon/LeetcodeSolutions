class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if(k<2)
            return 0;
        sort(nums.begin(),nums.end());
        int ans = INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            int left_idx = i;
            int right_idx = i+k-1;
            if(right_idx < nums.size())
            {
                ans = min(ans,nums[right_idx]-nums[left_idx]);
            }

        }
        return ans;
    }
};