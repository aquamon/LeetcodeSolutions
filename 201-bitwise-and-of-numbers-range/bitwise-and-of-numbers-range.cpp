class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        
          int ans = 0;
        for(int i=31;i>=0;i--)
        {
            long long int mask = 1<<i;

            if((mask&left) == (mask&right))
            {
                if(left&mask)
                    ans += mask;
            }
            else
                return ans;
        }
        return ans;
    }
};