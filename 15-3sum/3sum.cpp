class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());

        set<vector<int>>ans;

        for(int i=0;i<nums.size();i++)
        {
            int target = nums[i];

            int j=0 , k = nums.size()-1;
            while(j<k and j != i and k != i)
            {
                if(nums[j] + nums[k] == -nums[i])
                {
                    ans.insert({target,nums[j],nums[k]});
                    j++;
                    k--;
                }
                else if(nums[j] + nums[k] > -nums[i])
                {
                    k--;
                }
                else
                {
                    j++;
                }
            }
        }

        vector<vector<int>>A;
        for(auto it:ans)
            A.push_back(it);
        return A;
    }
};