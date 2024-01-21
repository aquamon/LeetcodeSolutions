class Solution {
public:

    bool check(string res)
    {
        // cout<<res<<endl;
        int i=0 , j= res.length()-1;

        while(i<=j)
        {
            if(res[i++] == res[j--])
            {
                continue;
            }
            return false;
        }
        return true;
    }
    bool isPalindrome(string s) {
        
        string res = "";

        for(char x:s)
        {
            if(isdigit(x))
                res += x;
            if(isalpha(x))
            {
                x = toupper(x);
                res += x;
            }
        }
        return check(res);
    }
};