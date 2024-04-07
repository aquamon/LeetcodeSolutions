class Solution {
public:
    bool checkValidString(string s) {
        
        int Open_count = 0;
        int Close_count = 0;

        for(int i=0;i<s.size();i++)
        {
            if(s[i] == '(' or s[i] == '*')
            {
                Open_count++;
            }
            else
            {
                Open_count--;
            }
            if(s[s.size()-1-i] == ')' or s[s.size()-1-i] == '*')
            {
                Close_count++;
            }
            else
            {
                Close_count--;
            }

            if(Open_count < 0 || Close_count < 0)
                return false;


        }

       
        return true;
    }
};