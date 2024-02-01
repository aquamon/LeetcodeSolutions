class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        
        vector<vector<int>>answer;

        if(nums.size() < 3 or nums.size()%3 != 0)
            return answer;
        
        sort(nums.begin(),nums.end());

        for(int i=0;i<nums.size();i+=3)
        {
            if((i+3-1) < nums.size() and (nums[i+3-1] - nums[i]) <= k)
            {
                int j=i;
                vector<int>curr;
                while(j<=(i+3-1) and j < nums.size())
                {
                    curr.push_back(nums[j]);
                    j++;
                }
                answer.push_back(curr);
            }
            else
            {
                return {};
            }
        }

        return answer;
    }
};