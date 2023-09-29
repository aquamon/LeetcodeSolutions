class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        
        if(nums.size() < 2)
            return true;
        
        bool incr = false, decr = false;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i] >= nums[i-1])
            {
                
                incr = true;
                continue;
            }
            else
            {
                incr = false;
                break;
            }
            
        }

        for(int j=nums.size()-2;j>=0;j--)
        {
            if(nums[j] >= nums[j+1])
            {
                decr = true;
                continue;
            }
            else
            {
                decr = false;
                break;
            }
        }

        return incr or decr;
    }
};