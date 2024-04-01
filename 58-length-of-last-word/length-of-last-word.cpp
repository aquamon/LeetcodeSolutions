class Solution {
public:
    int lengthOfLastWord(string s) {
        
        int j = s.size()-1;

        while(j >= 0 and s[j] == ' ')
        {
            j--;
        }

        int ans = 0;
        while(j >=0 and s[j] != ' ')
        {
            ans++;
            j--;
        }
        return ans;
    }
};