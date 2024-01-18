class Solution {
public:
 int solve(int idx,int N,vector<int>&nums,vector<int>&DP)
    {
        
        if(idx >= N-1)
            return 0;
        
        if(DP[idx] != 0)
            return DP[idx];
        
        int ans = 100000;
        
        for(int i=idx+1;i<=idx+nums[idx];i++)
        {
           int x = 1 + solve(i,N,nums,DP);
           ans= min(ans,x);
        }

        return DP[idx] = ans;
        
        
    }
    
    int jump(vector<int>& nums) {
        
       
        vector<int>DP(nums.size(),0);
        int ans = solve(0,nums.size(),nums,DP);
        return ans;
    }
};