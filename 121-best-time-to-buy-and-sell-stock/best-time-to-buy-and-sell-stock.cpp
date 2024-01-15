class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        vector<int>sufMax(prices.size(),0);
        sufMax[prices.size()-1] = prices[prices.size()-1];
        for(int i=prices.size()-2;i>=0;i--)
        {
            sufMax[i] = max(prices[i],sufMax[i+1]);
        }

       
        int ans = INT_MIN;
        for(int i=0;i<prices.size();i++)
        {
            ans = max(ans,sufMax[i]-prices[i]);
        }    
        return ans;
    }
};