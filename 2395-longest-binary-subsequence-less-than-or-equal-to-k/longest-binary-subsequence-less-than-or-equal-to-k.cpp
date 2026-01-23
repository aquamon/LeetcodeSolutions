class Solution {
public:
    int longestSubsequence(string s, int k) {
        
        int pos_msb_k = 32 - __builtin_clz(k);
        int answer = 0;
        int curr_sum = 0;
        for(int idx = 0 ; idx < s.size() ; idx++)
        {
            char ch = s[s.size()-1-idx];
            if(ch == '1')
            {
                if(idx < pos_msb_k and (curr_sum + (1<<idx)  <= k) )
                {
                    answer++;
                    curr_sum += (1<<idx);
                }
            }
            else
            {
                answer++;
            }
        }

        return answer;
    }
};