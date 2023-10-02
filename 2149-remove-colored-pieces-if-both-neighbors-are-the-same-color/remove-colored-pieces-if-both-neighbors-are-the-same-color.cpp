class Solution {
public:
    bool winnerOfGame(string s) {
        

        bool A = false, B = false;
        int chunkA = 0 , chunkB = 0;
        int countA = 0 , countB = 0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i] == 'A' and A)
            {
                chunkA++;
                B = false;
                chunkB = 0;
            }
            else if(s[i] == 'A' and !A)
            {
                chunkA = 1;
                A = true;
                B = false;
                chunkB = 0;
            }
            else if(s[i] == 'B' and B)
            {
                chunkB++;
                A = false;
                chunkA = 0;
            }
            else if(s[i] == 'B' and !B)
            {
                chunkB = 1;
                B = true;
                A = false;
                chunkA = 0;
            }

            if(chunkA >= 3)
            {
                countA++;
            }
            else if(chunkB >= 3)
            {
                countB++;
            }


        }

        
        // cout<<countA<<" "<<countB;
        if(countA > countB)
            return true;
        
        return false;
    }
};