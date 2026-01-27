class Solution {
public:
    int maxFreqSum(string s) {
        int vowel = 0;
        int consonant = 0;

        int map[26] = {0};

        for(char x:s)
        {
            int a = x-'a';
            map[a] += 1;
        }

        for(int i=0;i<26;i++)
        {
            if(i==0 or i==4 or i==8 or i==14 or i==20)
            {
                vowel = max(vowel,map[i]);
            }
            else
            {
                consonant = max(consonant,map[i]);
            }
        }

        return vowel+consonant;


    }
};