class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        int freqR[26] = {0};
        int freqM[26] = {0};

        for(char x:ransomNote)
        {
            freqR[x-'a']++;
        }
         for(char x:magazine)
        {
            freqM[x-'a']++;
        }

        for(int i=0;i<ransomNote.length();i++)
        {
            if(freqR[ransomNote[i]-'a'] > freqM[ransomNote[i]-'a'])
                return false;
        }
        return true;
    }
};