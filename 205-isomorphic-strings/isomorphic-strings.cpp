class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        if(s.size() != t.size())
            return false;
       unordered_map<char,char>M1;
       unordered_map<char,char>M2;
       

       for(int i=0;i<t.size();i++)
       {
           if(M1.find(s[i]) != M1.end())
           {
               if(M1[s[i]] != t[i])
                return false;
           }
           else
           {
               if(M2.find(t[i]) != M2.end())
               {
                   return false;
               }
               else
               {
                   M1[s[i]] = t[i];
                   M2[t[i]] = s[i];
               }
           }
       }
       return true;
    }
};