class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int,int>M;
        for(int i=0;i<nums.size();i++)
        {
            if(M.find(target-nums[i]) != M.end())
            {
                return {i,M[target-nums[i]]};
            }
            M.insert({nums[i],i});
        }

        
        return {};
    }
};