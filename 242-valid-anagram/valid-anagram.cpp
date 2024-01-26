class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if(s.size() != t.size())
            return false;
        int freqS[256] = {0};
        // int freqT[256] = {0};

        for(int i=0;i<s.size();i++)
        {
            freqS[s[i]]++;
            freqS[t[i]]--;

        }

        for(int i=0;i<256;i++)
        {
            if(freqS[i] != 0)
                return false;
        }
        return true;
    }
};