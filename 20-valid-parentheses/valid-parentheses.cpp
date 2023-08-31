class Solution {
public:
    bool isValid(string s) {
        
        stack<char>S;

        for(int i=0;i<s.length();i++)
        {
            if(s[i] == '(' or s[i] == '{' or s[i] == '[')
                S.push(s[i]);
            else
            {
                if(S.empty())
                    return false;
                char X = S.top();
                S.pop();
                if((X == '[' and s[i] != ']') or (X == '{' and s[i] != '}') or (X == '(' and s[i] != ')'))
                    return false;
                
            }
        }
        return S.empty();
    }
};