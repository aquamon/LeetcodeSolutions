class Solution {
public:
    bool is_non_decreasing(vector<int>&nums)
    {
        if(nums.size() < 2)
            return true;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i-1] > nums[i])
                return false;
        }
        return true;
    }

    vector<int> pair_sum(vector<int>&nums)
    {
        if(nums.size()<2)
            return nums;
        
        int curr_sum = INT_MAX;
        int x = -1 , y = -1;
        for(int i=nums.size()-1;i>0;i--)
        {
            if(nums[i]+nums[i-1] <= curr_sum)
            {
                y=i;
                x=i-1;
                curr_sum = (nums[i]+nums[i-1]);
            }
        }

        vector<int>result;
        for(int i=0;i<nums.size();)
        {
            if(i==x)
            {
                result.push_back(nums[x]+nums[y]);
                i = i+2;
            }
            else
            {
                result.push_back(nums[i]);
                i++;
            }
        }
        return result;
    }



    int minimumPairRemoval(vector<int>& nums) {
        
        int ans = 0;

        while(true)
        {
            if(is_non_decreasing(nums))
            {
                return ans;
            }
            ans++;
            nums = pair_sum(nums);
        }
        return ans;

    }
};