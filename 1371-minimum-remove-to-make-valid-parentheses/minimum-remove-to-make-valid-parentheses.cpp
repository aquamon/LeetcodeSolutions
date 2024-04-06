class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
        stack<int>ST;
        
        map<int,int>invalid;
        for(int i=0;i<s.size();i++)
        {
            if(s[i] == '(')
                ST.push(i);
            else if(s[i] == ')')
            {
                if(!ST.empty())
                {
                    ST.pop();
                }
                else
                {
                    invalid[i]++;
                }
            }
        }
        while(!ST.empty())
        {
            invalid[ST.top()]++;
            ST.pop();
        }

        string res = "";


        for(int i=0;i<s.size();i++)
        {
            if(invalid.find(i) == invalid.end())
                res += s[i];
        }

        return res;

    }
};