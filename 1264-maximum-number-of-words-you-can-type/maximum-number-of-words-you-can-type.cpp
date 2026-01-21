class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        
        map<char,int>HM;
        for(char x:brokenLetters)
            HM[x]++;
        int ans = 0;
        for(int i=0;i<text.size();i++)
        {
            bool can_type = true;
            while(i<text.size() and text[i] != ' ')
            {
                if(HM[text[i]] != 0)
                {
                    can_type = false;
                }
                i++;
            }
            if(can_type)
            {
                ans++;
            }

        }
        return ans;
    }
};