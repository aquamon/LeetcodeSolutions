class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        
        int prev = 0, curr = 0;
        int ans = INT_MIN;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i] > nums[i-1])
            {
                curr = i;
                int diff = curr - prev;
                ans = max(ans,diff);
            }
            else
            {
                prev = i;
                curr = i;
            }
        }

        prev = 0 , curr = 0;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i] < nums[i-1])
            {
                curr = i;
                int diff = curr - prev;
                ans = max(ans,diff);
            }
            else
            {
                prev = i;
                curr = i;
            }
        }

        return max(1,ans+1);
    }
};