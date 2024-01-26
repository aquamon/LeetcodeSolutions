class Solution {
public:
    bool isHappy(int n) {
        
        unordered_map<int,int> M ;

        int num = n;
        while(true)
        {
            int curr = 0;
            while(num > 0)
            {
                int digit = num%10;
                curr += digit*digit;
                num/=10;
            }
            if(M.find(curr) != M.end())
                return false;
            if(curr == 1)
                return true;
            M[curr]++;
            num = curr;
        }

    }
};