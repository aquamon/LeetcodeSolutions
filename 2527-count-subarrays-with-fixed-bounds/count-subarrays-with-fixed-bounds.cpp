class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        
        int subArrayStart = 0;
        int min_idx = -1;
        int max_idx = -1;

        long long res = 0;

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] < minK or nums[i] > maxK)
            {
                subArrayStart = i+1;
                min_idx = -1;
                max_idx = -1;
            }
            if(nums[i] == minK)
            {
                min_idx = i;
            }
            if(nums[i] == maxK)
            {
                max_idx = i;
            }
            res += max(0,min(min_idx,max_idx)-subArrayStart+1);
        }
        return res;
    }
};