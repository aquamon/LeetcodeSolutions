class Solution {
public:
    int M,N;
    string W1,W2;
    vector<vector<int>>DP;
    int lcs(int i, int j)
    {
        if(i<0 || j<0)
            return 0;
        if(DP[i][j] != -1)
            return DP[i][j];
        if(W1[i] == W2[j])
        {
            return DP[i][j] =  1+lcs(i-1,j-1);
        }
        else
        {
            return DP[i][j] =  max(lcs(i,j-1) , lcs(i-1,j));
        }

        
    }
    int longestCommonSubsequence(string text1, string text2) {
        
        M = text1.size();
        N = text2.size();
        W1 = text1;
        W2 = text2;
        
        DP.assign(M,vector(N,-1));
        int ans = lcs(M-1,N-1);

        return ans;
    }
};