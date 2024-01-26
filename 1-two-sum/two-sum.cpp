class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int,int>M;
        for(int i=0;i<nums.size();i++)
        {
            M.insert({nums[i],i});
        }

        for(int i=0;i<nums.size();i++)
        {
            if(M.find(target-nums[i]) != M.end() and M[target-nums[i]] != i)
            {
                return {i,M[target-nums[i]]};
            }
        }
        return {};
    }
};