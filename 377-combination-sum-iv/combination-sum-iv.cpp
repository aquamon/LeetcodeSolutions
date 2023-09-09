class Solution {
public:

    int solve( vector<int>&nums,int T,vector<int>&DP)
    {
        
        if(T == 0)
            return 1;
        if(T < 0 )
            return 0;
        if(DP[T] != -1)
            return DP[T];
        
        
        int x = 0;
        for(int i=0;i<nums.size();i++)
        {
            x += solve(nums,T-nums[i],DP);
        }
        return DP[T] = x;
    }
    int combinationSum4(vector<int>& nums, int target) {
        
        vector<int>DP(target+1,-1);
        return solve(nums,target,DP);
    }
};