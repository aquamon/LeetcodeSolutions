class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() < 1)
            return 0;
        if(nums.size() == 1)
            return 1;
        unordered_map<int,int>M,vis;

        for(int X : nums)
        {
            M[X]++;
        }

        int ans = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(M.find(nums[i]-1) != M.end())
                continue;
            else
            {
                if(vis.find(nums[i]) != vis.end())
                    continue;
                vis[nums[i]] = 1;

                int x = nums[i], len = 0;

                while(M.find(x) != M.end())
                {
                    len++;
                    x++;
                }
                ans = max(ans,len);
                
            }
        }
        return ans;
    }
};