class Solution {
public:
    string removeDuplicates(string s, int k) {
        
        stack<pair<char,int>>ST;

        for(int i=0;i<s.size();i++)
        {
            if(ST.empty())
            {
                ST.push({s[i],1});
            }
            else
            {
                pair<char,int> TOP = ST.top();

                if(s[i] == TOP.first)
                {
                    if(TOP.second+1 == k)
                    {
                        while(!ST.empty() and ST.top().first == s[i])
                        {
                            ST.pop();
                        }
                    }
                    else
                    {
                        ST.push({s[i] , TOP.second+1});
                    }
                }
                else
                {
                    ST.push({s[i],1});
                }
            }
        }
        string res = "";
        while(!ST.empty())
        {
            res += ST.top().first;
            ST.pop();
        }

        reverse(res.begin(),res.end());
        return res;
    }
};