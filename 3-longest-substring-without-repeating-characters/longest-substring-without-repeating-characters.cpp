class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        if(s.size() < 1)
            return 0;
        
        int freq[256] = {0};

        int i=0 , j=1, ans = 1;
        freq[s[i]]++;
        while(j < s.length())
        {
            while(j < s.length() and freq[s[j]] == 0)
            {
                freq[s[j]]++;
                j++;
            }
            ans = max(ans,j-i);
            freq[s[i]]--;
            i++;
        }
        return ans;
    }
};