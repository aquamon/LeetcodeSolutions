class Solution {
public:

    bool static cmp(string &A, string &B)
    {
        return A.length() < B.length();
    }

    bool isSubseq(string s, string t)
    {
        int j=0;
        for(int i=0;i<t.length();i++)
        {
            if(s[j] == t[i])
            {
                j++;
            }
        }
        return j == s.length();
    }
    int longestStrChain(vector<string>& words) {
        
        
        sort(words.begin(),words.end(),cmp);
        int maxLen  = 1;
        vector<int>DP(words.size(),1);
        for(int i=1;i<words.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                if(isSubseq(words[j] , words[i]) && words[j].length()+1 == words[i].length())
                {
                    DP[i] = max(DP[i],DP[j]+1);
                }
            }
            maxLen = max(maxLen,DP[i]);
        }

        return maxLen;
    }
};