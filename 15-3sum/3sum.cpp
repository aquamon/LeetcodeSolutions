class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());

        vector<vector<int>>ans;

        // set<vector<int>>ST;

        for(int i=0;i<nums.size();i++)
        {
            // int target = nums[i];
            if(i > 0 and nums[i]==nums[i-1])
            {
                continue;
            }
            int j=i+1 , k = nums.size()-1;
            while(j<k)
            {
                if(nums[j] + nums[k] == -nums[i])
                {
                    ans.push_back({nums[i],nums[j],nums[k]});
                    
                    int v1 = nums[j] , v2 = nums[k];
                    if(v1 == v2)
                        break;
                    while(v1 == nums[j] and j < nums.size())
                        j++;
                    while(v2 == nums[k] and k >= 0 )
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

        // vector<vector<int>>A;
        // for(auto it:ST)
        //     A.push_back(it);
        // return A;

        return ans;
    }
};