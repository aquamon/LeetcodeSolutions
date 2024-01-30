class Solution {
public:
    int calculate(string s) {
        
        stack<int>ST;
        int result = 0;
        int sign = 1;
        int num = 0;

        for(int i=0;i<s.size();i++)
        {
            if(isdigit(s[i]))
            {
                num = num*10 + (s[i]-'0');
            }
            else if(s[i] == '+')
            {
                result += num*sign;
                num = 0;
                sign = 1;
            }
            else if(s[i] == '-')
            {
                result += num*sign;
                num = 0;
                sign = -1;
            }
            else if(s[i] == '(')
            {
                ST.push(result);
                ST.push(sign);
                num = 0;
                sign = 1;
                result = 0;
            }
            else if(s[i] == ')')
            {
                result += num*sign;
                num = 0;

                int last_sign = ST.top();
                ST.pop();
                int last_result = ST.top();
                ST.pop();

                result *= last_sign;
                result += last_result;
            }

        }
        result += num*sign;

        return result;
    }
};