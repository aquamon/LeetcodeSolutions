class Solution {
public:
    int maxSubArray(vector<int>& nums) {

       int ans = nums[0];
       nums[0] = nums[0] < 0 ? 0 : nums[0];
       for(int i=1;i<nums.size();i++)
       {
            nums[i] += nums[i-1];
            ans = max(ans,nums[i]);
            if(nums[i] < 0)
                nums[i] = 0;
       }
       return ans;
        
    }
};