class Solution {
public:
    int firstUniqChar(string s) {
        
        int freq[26] = {0};

        for(int i=0;i<s.size();i++)
        {
            if(freq[s[i] - 'a'] == 0)
            {
                freq[s[i]-'a'] = -(i+1);
            }
            else
            {
                freq[s[i]-'a'] = i+1;
            }
        }

        int ans = INT_MIN;
        for(int i=0;i<26;i++)
        {
            if(freq[i] < 0)
            {
                ans = max(ans,freq[i]);
            }
        }

        return ans == INT_MIN ? -1 : -1*ans - 1;
    }
};