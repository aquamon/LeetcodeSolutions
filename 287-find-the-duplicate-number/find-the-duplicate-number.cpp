class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] == i)
                continue;
            
            while(nums[i] != i)
            {
                if(nums[i] == nums[nums[i]])
                    return nums[i];
                swap(nums[i],nums[nums[i]]);
                
            }
        }
        return 1;
    }
};