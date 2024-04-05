class Solution {
public:
    string makeGood(string s) {
        
        stack<char>ST;

        char prev = '0';
        string res = "";
        for(char x : s)
        {
            if(prev == '0')
            {
                prev = x;
                res.push_back(x);
            }
            else
            {
                if(abs(x-prev) == abs('A'-'a'))
                {
                    res.pop_back();
                    if(res.size() > 0)
                        prev = res.back();
                    else
                        prev = '0';
                }
                else
                {
                    res.push_back(x);
                    prev = x;
                }
            }
        }
        return res;

        // string res = "";
        // while(!ST.empty())
        // {
        //     res = ST.top() + res;
        //     ST.pop();
        // }
        // return res;
    }
};