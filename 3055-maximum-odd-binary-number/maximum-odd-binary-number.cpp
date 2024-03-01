class Solution {
public:
    string maximumOddBinaryNumber(string s) {

        for(int i=0;i<s.size();i++)
        {
            if(s[i] == '1')
            {
                swap(s[i],s[s.size()-1]);
                break;
            }
        }    
        int i=0 , j = s.size()-2;

        while(i < j)
        {
            while(s[i] == '1' and i < j)
            {
                i++;
            }
            while(s[j] == '0' and j > i)
            {
                j--;
            }
            if(i < s.size() and j >=0 )
                swap(s[i],s[j]);

        }

        return s;
    }
};