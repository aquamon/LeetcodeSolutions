class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        if(s.size() < 1)
            return 0;
        int i=0,j=1;
        unordered_map<char,int>M;
        M[s[i]]++;
        int ans = 1;
        while(j < s.size())
        {
            while(j < s.size() and M[s[j]] == 0)
            {
                M[s[j]]++;
                j++;
            }
            ans = max(ans,j-i);
            M[s[i]]--;
            i++;
        }

        return ans;
    }
};