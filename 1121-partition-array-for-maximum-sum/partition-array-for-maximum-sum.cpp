class Solution {
public:
    int solve(int start, vector<int>&arr, int k, vector<int>&dp)
    {
        int N = arr.size();
        if(start >= N )
            return 0;
        if(dp[start] != -1)
            return dp[start];
        
        int ans = 0 , curr_Max = 0 , end = min(N,start+k);
        for(int i=start;i<end;i++)
        {
            curr_Max = max(curr_Max,arr[i]);

            ans = max(ans, curr_Max * (i-start+1) + solve(i+1,arr,k,dp));
        }

        return dp[start] = ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        
        vector<int>dp(arr.size(),-1);

        return solve(0,arr,k,dp);


    }
};