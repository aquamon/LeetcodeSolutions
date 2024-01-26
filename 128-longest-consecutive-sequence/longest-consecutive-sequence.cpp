class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        if(nums.size() < 1)
            return 0;
        unordered_map<int,int>M;

        for(int i=0;i<nums.size();i++)
        {
            M[nums[i]]++;
        }

        int ans = 1;
        for(int i=0;i<nums.size();i++)
        {
            if(M.find(nums[i]-1) == M.end())
            {
                int length = 1;
                int curr = nums[i];
                while(true)
                {
                    if(M.find(++curr) != M.end())
                        length += 1;
                    else
                        break;
                }
                ans = max(ans,length);
            }
        }
        return ans;
    }
};