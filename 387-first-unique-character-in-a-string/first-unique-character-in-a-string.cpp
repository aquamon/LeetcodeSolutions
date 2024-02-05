class Solution {
public:
    int firstUniqChar(string s) {
        
        int freq[26] = {0};
    
        for(char x:s)
            freq[x-'a']++;
        
        int idx = 0;
        for(char x : s)
        {
            if(freq[x-'a'] == 1)
                return idx;
            idx++;
        }

        return -1;
    }
};