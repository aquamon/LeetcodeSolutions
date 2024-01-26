class Solution {
public:
    void split(string s,vector<string>&A)
    {
        string curr = "";
        for(int i=0;i<s.length();i++)
        {
            if(s[i] == ' ')
            {
                A.push_back(curr);
                curr.clear();
                continue;
            }
            curr+=s[i];
        }
        A.push_back(curr);
    }
    bool wordPattern(string pattern, string s) {
        
        
        map<string,char>M;
        map<char,int>M2;
        vector<string>A;

        split(s,A);
       
        if(A.size() != pattern.size())
            return false;
       
        for(int i=0;i<A.size();i++)
        {
            if(M.find(A[i]) == M.end() and M2.find(pattern[i]) == M2.end())
            {
                M[A[i]] = pattern[i];
                M2[pattern[i]]++;
            }
            else
            {
                if(M[A[i]] != pattern[i])
                    return false;
            }
        }
        return true;
            
    }
};