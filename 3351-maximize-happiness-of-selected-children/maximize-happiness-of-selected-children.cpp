class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        
        long long ans = 0;
        int count = 0;

        sort(happiness.begin(),happiness.end());

        for(int i=happiness.size()-1;i>=0;i--)
        {
            if(k > 0)
            {
                if(happiness[i] - count <= 0)
                    break;
                ans += happiness[i];
               
                ans -= count;
                count++;
                k--;
            }
        }
        return ans;
    }
};