class Solution {
public:
    bool closeStrings(string word1, string word2) {
        
        
        if(word1.length() != word2.length())
            return false;
       
        int freq1[26] = {0};
        int freq2[26] = {0};

        for(char x : word1)
        {
            freq1[x-'a']++;
        }
        for(char x : word2)
        {
            freq2[x-'a']++;
        }

        for(int i=0;i<26;i++)
        {
            if(freq1[i] != 0 and freq2[i] == 0)
                return false;
            if(freq1[i] == 0 and freq2[i] != 0)
                return false;
        }

        sort(freq1,freq1+26);
        sort(freq2,freq2+26);

        for(int i=0;i<26;i++)
        {
            if(freq1[i] != freq2[i])
                return false;
        }

        return true;
    }
};