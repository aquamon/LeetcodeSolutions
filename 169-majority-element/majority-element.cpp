class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int candidate = NULL;
        int vote = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(candidate == NULL)
            {
                candidate = nums[i];
                vote++;
            }
            else
            {
                if(nums[i] == candidate)
                {
                    vote++;
                }
                else
                {
                    vote--;
                    if(vote == 0)
                    {
                        candidate = nums[i];
                        vote++;
                    }
                }
                 
            }
        }
        return candidate;
    }
};