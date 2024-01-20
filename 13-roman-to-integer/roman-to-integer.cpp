class Solution {
public:
    int romanToInt(string s) {
        
        int ans = 0;
        
        for(int i=s.size()-1;i>=0;i--)
        {
            if(s[i] == 'I')
            {
                ans += 1;
                if(i+1 < s.size() and s[i+1] == 'V')
                {
                    ans -= 1;
                    ans -= 5;
                    ans += 4;
                }
                 if(i+1 < s.size() and s[i+1] == 'X')
                {
                    ans -= 1;
                    ans -= 10;
                    ans += 9;
                }
            }
            else if(s[i] == 'V')
            {
                ans+=5;
            }
            if(s[i] == 'X')
            {
                ans += 10;
                  if(i+1 < s.size() and s[i+1] == 'L')
                {
                    ans -= 10;
                    ans -= 50;
                    ans += 40;
                }
                  if(i+1 < s.size() and s[i+1] == 'C')
                {
                    ans -= 10;
                    ans -= 100;
                    ans += 90;
                }
            }
            if(s[i] == 'L')
            {
                ans += 50;
            }
            if(s[i] == 'C')
            {
                ans += 100;
                  if(i+1 < s.size() and s[i+1] == 'D')
                {
                    ans -= 100;
                    ans -= 500;
                    ans += 400;
                }
                  if(i+1 < s.size() and s[i+1] == 'M')
                {
                    ans -= 100;
                    ans -= 1000;
                    ans += 900;
                }
            }
            if(s[i] == 'D')
            {
                ans += 500;
            }
            if(s[i] == 'M')
            {
                ans += 1000;
            }
        }
        return ans;
    }
};