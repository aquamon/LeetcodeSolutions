class Solution {
public:
    string makeGood(string s) {
        
        stack<char>ST;

        for(char x : s)
        {
            if(ST.empty())
                ST.push(x);
            else
            {
                char prev = ST.top();
                if(abs(x-prev) == 32)
                {
                    ST.pop();
                }
                else
                {
                    ST.push(x);
                }
            }
        }

        string res = "";
        while(!ST.empty())
        {
            res = ST.top() + res;
            ST.pop();
        }
        return res;
    }
};