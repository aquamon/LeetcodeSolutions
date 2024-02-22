class Solution {
public:
    int minAddToMakeValid(string s) {
        
        stack<char>ST;
        int count = 0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i] == '(')
                ST.push(s[i]);
            else
            {
                if(!ST.empty())
                    ST.pop();
                else
                    count++;
            }
        }

        return count + ST.size();
    }
};