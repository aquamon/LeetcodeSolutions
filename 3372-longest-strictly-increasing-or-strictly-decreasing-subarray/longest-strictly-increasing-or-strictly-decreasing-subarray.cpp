class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        
        int answer = 1 , increasing_length = 1 , decreasing_length = 1;

        for(int pos = 0 ; pos < nums.size()-1; pos++)
        {
            if(nums[pos+1] > nums[pos])
            {
                increasing_length++;
                decreasing_length = 1;
            }
            else if(nums[pos] > nums[pos+1])
            {
                decreasing_length++;
                increasing_length = 1;
            }
            else
            {
                increasing_length = 1;
                decreasing_length = 1;
            }

            answer = max({answer,increasing_length,decreasing_length});
        }
        return answer;
    }
};