class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        vector<int>suffix(nums.size()+1,1);

        for(int i=nums.size()-2;i>=0;i--)
        {
            suffix[i] = nums[i+1]*suffix[i+1];
        }

        vector<int>ans;

        int prefix = 1;
        for(int i=0;i<nums.size();i++)
        {
            ans.push_back(suffix[i]*prefix);

            prefix *= nums[i];
        }

        return ans;
    }
};