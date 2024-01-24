class Solution {
public:
    string minWindow(string s, string t) {
        
        if(t.length()<1)
            return "";
        int freqS[256] = {0};
        int freqT[256] = {0};

        int dist_char = 0;
        for(int i=0;i<t.length();i++)
        {
            if(freqT[t[i]] == 0)
                dist_char++;
            freqT[t[i]]++;
        }

       
        int count = 0;
        int start = 0, end = 0;
        for(int j=0;j<s.length();j++)
        {
            freqS[s[j]]++;
            if(freqS[s[j]] == freqT[s[j]])
                count++;
            
            if(count == dist_char)
            {
                end = j;
                break;
            }
        }

        if(count < dist_char)
            return "";
        
        int len = end-start+1;
        int ans_s = start, ans_e = end;

        while(end < s.length())
        {
            while(freqS[s[start]] > freqT[s[start]])
            {
                freqS[s[start]]--;
                start++;
            }

            if((end-start+1) < len)
            {
                len = end-start+1;
                ans_s = start;
                ans_e = end;
            }
            end++;
            if(end < s.length())
                freqS[s[end]]++;
        }

        return s.substr(ans_s,len);
    }
};