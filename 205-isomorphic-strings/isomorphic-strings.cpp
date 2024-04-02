class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        if(s.size() != t.size())
            return false;
        unordered_map<char , char > S_map_to_T , T_map_to_S;

        for(int i=0;i<s.size();i++)
        {
            if(S_map_to_T.find(s[i]) != S_map_to_T.end())
            {
                if(S_map_to_T[s[i]] != t[i])
                    return false;
            }
            else
            {
                if(T_map_to_S.find(t[i])!= T_map_to_S.end())
                {
                    return false;
                }
                else
                {
                    S_map_to_T[s[i]] = t[i];
                    T_map_to_S[t[i]] = s[i];
                }
            }
        }
        return true;
        
    }
};