class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>res;
        if(nums.size() < 1)
            return res;
        string curr = to_string(nums[0]);

        for(int i=1;i<nums.size();i++)
        {
            if(nums[i-1] == nums[i]-1)
            {
                continue;
            }
            else
            {
                if(to_string(nums[i-1]) != curr)
                {
                    curr += "->";
                    curr += to_string(nums[i-1]);
                }

                
                res.push_back(curr);
                curr = to_string(nums[i]);
            }
        }

        if(curr != to_string(nums[nums.size()-1]))
        {
            curr += "->";
            curr += to_string(nums[nums.size()-1]);
        }
        res.push_back(curr);
        return res;
    }
};