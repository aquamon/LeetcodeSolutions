class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        unordered_map<char,int>M1;
        unordered_map<char,int>M2;
        unordered_map<char,char>REP;
        for(char x : s)
        {
            M1[x]++;
        }
        for(char x : t)
        {
            M2[x]++;
        }

        if(M1.size() != M2.size())
        {
            return false;
        }

        for(int i=0;i<s.size();i++)
        {
            if(M1[s[i]] != M2[t[i]])
                return false;
            if(REP.find(s[i]) == REP.end())
                REP[s[i]] = t[i];
        }

        for(int i=0;i<s.size();i++)
        {
            s[i] = REP[s[i]];
        }
        return s==t;
    }
};