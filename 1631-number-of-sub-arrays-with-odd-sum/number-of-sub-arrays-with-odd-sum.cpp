#define M 1000000007
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        
        long long int prefix = -1;

        int ans = 0;
        int odd = 0;
        int even = 0;
        for(int i=0;i<arr.size();i++)
        {
            if(i==0)
            {
                prefix = arr[i];
               
            }
            else
            prefix += arr[i];
                
            
            if(prefix&1)
            {
                ans = (ans%M + (1%M+even%M)%M)%M;
            }
            else
            {
                ans = (ans%M + odd%M)%M;
            }
            if(prefix&1)
                odd++;
            else
                even++;
        }

        return ans%M;
    }
};