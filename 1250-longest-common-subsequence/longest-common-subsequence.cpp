class Solution {
public:

    int lcs(int i, string text1,int j,string text2, vector<vector<int>>&M)
    {
        for(int i=0;i<text1.size()+1;i++)
            M[i][0] = 0;
        for(int j=0;j<text2.size()+1;j++)
            M[0][j] = 0;
        
        for(int i=1;i<=text1.size();i++)
        {
            for(int j=1;j<=text2.size();j++)
            {
                if(text1[i-1] == text2[j-1])
                    M[i][j] = 1+M[i-1][j-1];
                else
                    M[i][j] = max(M[i-1][j] , M[i][j-1]);
            }
        }
        return M[text1.size()][text2.size()];
    }
    int longestCommonSubsequence(string text1, string text2) {
        
        
        vector<vector<int>>M(text1.size()+1,vector<int>(text2.size()+1,-1));
        int ans = lcs(text1.size()-1,text1,text2.size()-1,text2,M);

        return ans;
    }
};