class Solution {
public:
    int ans(int N,int i,vector<int>&MEMO)
    {
       
        if(i > N)
            return 0;
        if(i == N)
            return 1;
         if(MEMO[i] != -1)
            return MEMO[i];
        return MEMO[i] = ans(N,i+1,MEMO) + ans(N,i+2,MEMO);
    }
    int climbStairs(int n) {
        
        vector<int>MEMO(n+1,-1);
        
        return ans(n,0,MEMO);
    }
};