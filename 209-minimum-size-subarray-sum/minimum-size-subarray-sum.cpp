class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0;
        int prev = 0;

        int ans = INT_MAX;

        for(int i=0;i<nums.size();i++)
        {
            sum += nums[i];
            while(sum >= target)
            {
                ans = min(ans,i-prev+1);
                sum -= nums[prev];
                prev++;
            }
        }
        if(ans == INT_MAX)
            return 0;
        return ans;
    }
};