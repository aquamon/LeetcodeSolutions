class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        if(s.size() != t.size())
            return false;
        int freqS[256] = {0};
        int freqT[256] = {0};

        for(int i=0;i<s.size();i++)
        {
            
            if(freqT[t[i]] != freqS[s[i]])
                return false;
            freqS[s[i]] = i+1;;
            freqT[t[i]] = i+1;
        }
        return true;
        
    }
};