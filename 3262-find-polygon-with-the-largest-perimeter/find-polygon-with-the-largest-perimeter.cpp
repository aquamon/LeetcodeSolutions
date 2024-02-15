class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        long long int prefix = nums[0] + nums[1];
        long long int ans = -1;
        for(int j=2;j<nums.size();j++)
        {
            if(nums[j] < prefix)
            {
                ans = max(ans,nums[j]+prefix);
            }
            prefix += nums[j];
        }

        return ans==-1?-1:ans;
    }
};