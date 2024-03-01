class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        
        vector<char>one , zero;

        for(char x : s)
        {
            if(x == '1')
                one.push_back(x);
            else
                zero.push_back(x);
        }

        string res = "1";

        for(char x : zero)
            res = x + res;
        
        one.pop_back();

        for(char x : one)
            res = x + res;

        return res;
    }
};