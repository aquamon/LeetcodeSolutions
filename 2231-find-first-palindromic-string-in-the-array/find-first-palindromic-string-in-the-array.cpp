class Solution {
public:
    bool isPalindrome(string S)
    {
        int i=0 , j = S.length()-1;

        while(i<=j)
        {
            if(S[i] == S[j])
            {
                i++;
                j--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        
        for(string x : words)
        {
            if(isPalindrome(x))
                return x;
        }
        return "";
    }
};