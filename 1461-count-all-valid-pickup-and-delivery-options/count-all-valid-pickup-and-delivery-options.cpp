class Solution {
public:


    
    int mod = 1e9+7;
    unsigned long long solve(unsigned long long unpicked, unsigned long long undelivered, vector<vector<unsigned long long>>&DP)
    {
        if(unpicked == 0 and undelivered==0)
            return 1;
        if(unpicked < 0 or undelivered < 0 or undelivered < unpicked)
            return 0;
        if(DP[unpicked][undelivered] != -1)
            return DP[unpicked][undelivered];
        
        unsigned long long ans = 0;

        ans = ( ans%mod + (unpicked%mod*solve(unpicked-1,undelivered,DP)%mod)%mod)%mod;

        ans = ans%mod;

        ans += (undelivered-unpicked) * solve(unpicked,undelivered-1,DP);

        ans = ans%mod;

        return DP[unpicked][undelivered] = ans ;

    }
    
    int countOrders(int n) {

        vector<vector<unsigned long long>>DP(n+1,vector<unsigned long long>(n+1,-1));

        return solve(n,n,DP);
    }
};