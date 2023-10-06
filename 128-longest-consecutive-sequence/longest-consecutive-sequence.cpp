class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_map<int,int>M;
        int ans = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(M.find(nums[i]) != M.end())
                continue;
            
            int left_streak = 0, right_streak = 0;

            if(M.find(nums[i]-1) != M.end())
                left_streak = M[nums[i]-1];
            if(M.find(nums[i] + 1) != M.end())
                right_streak = M[nums[i] + 1];
            
            ans = max(ans,1+left_streak + right_streak);

            M[nums[i]] = 1 + left_streak + right_streak;
            M[nums[i]-left_streak] = 1 + left_streak + right_streak;
            M[nums[i]+right_streak] = 1 + left_streak + right_streak;


        }
        return ans;
    }
};