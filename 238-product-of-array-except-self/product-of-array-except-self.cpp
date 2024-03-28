class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        vector<int>prefix(nums.size(),0);
        prefix[0] = nums[0];
        vector<int>suffix(nums.size(),0);
        suffix[nums.size()-1] = nums[nums.size()-1];
        for(int i=1;i<nums.size();i++)
        {
            prefix[i] = prefix[i-1]*nums[i];
        }

        for(int i=nums.size()-2;i>=0;i--)
        {
            suffix[i] = suffix[i+1]*nums[i];
        }

        vector<int>ans;
        for(int i=0;i<nums.size();i++)
        {
            
            int pre = 1, suf = 1;

            if(i != 0)
                pre = prefix[i-1];
            
            if(i != nums.size()-1)
                suf = suffix[i+1];
            
            ans.push_back(pre*suf);


        }

        return ans;
    }
};