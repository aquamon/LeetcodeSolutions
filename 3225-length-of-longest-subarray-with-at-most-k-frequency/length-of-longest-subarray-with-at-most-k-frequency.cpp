class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        
        if(nums.size() <= 1 and k==1)
            return 1;
        unordered_map<int,int>M;
        int ans = 0;
        for(int i=0,j=0;j<nums.size();)
        {
            if(M[nums[j]] < k)
            {
                M[nums[j]]++;
                ans = max(ans,j-i+1);
                j++;
            }
            else
            {
                // if(nums[i] != nums[j])
                // {
                    M[nums[i]]--;
                    i++;
            //     }
            //    else
            //    {

            //    }
            }
            
        }
        return ans;
    }
};