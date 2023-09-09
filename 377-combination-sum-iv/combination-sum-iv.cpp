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
    unsigned long long tab(vector<int>&nums,long T,vector<unsigned long long >&DP)
    {
        DP[0] = 1;

        for(long long  i=1;i<T+1;i++)
        {
            for(long long  x : nums)
            {
                if(i-x >= 0)
                    DP[i] += DP[i-x];
            }
        }
        return DP[T];
    }
    int combinationSum4(vector<int>& nums, int target) {
        
        vector<unsigned long long>DP(target+1,0);
        return tab(nums,target,DP);
    }
};
