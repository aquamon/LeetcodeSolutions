class Solution {
public:
    string minWindow(string s, string t) {
        
        int freqS[256] = {0};
        int freqT[256] = {0};
        int dist_char = 0;
        for(int i=0;i<t.size();i++)
        {
            if(freqT[t[i]] == 0)
            {
                dist_char++;
            }
            freqT[t[i]]++;
        }

        int count = 0;
        int end = 0;
        for(int i=0;i<s.size();i++)
        {
            freqS[s[i]]++;
            if(freqS[s[i]] == freqT[s[i]])
            {
                count++;
            }
            if(count == dist_char)
            {
                end = i;
                break;
            }
        }

        if(count < dist_char)
            return "";
        int start = 0;
        int ans_start = 0, ans_end = end;
        int len = end-start+1;
    

        while(end < s.size())
        {
            while(freqS[s[start]] > freqT[s[start]])
            {
                freqS[s[start]]--;
                start++;
                
            }

            if(end-start+1 < len)
            {
                ans_start = start;
                ans_end = end;
                len = end-start+1;
            }
            end++;
            if(end < s.size())
                freqS[s[end]]++;
        }

        return s.substr(ans_start,len);




    }
};