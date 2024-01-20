class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0;

        int i = s.length()-1;

        int start = false;
        int count  =0 ;
        while(i >= 0)
        {
            if(start == false and s[i] == ' ')
            {
                i--;
                continue;
            }
            else if(start == false and s[i] != ' ')
            {
                start = true;
                i--;
                count++;
            }
            else if(start == true and s[i] != ' ')
            {
                i--;
                count++;
            }
            else
                break;
        }
        return count;
    }
};