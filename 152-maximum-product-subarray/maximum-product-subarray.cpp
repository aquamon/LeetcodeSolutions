class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int ans = INT_MIN;
        int l = 1 , r = 1;

        for(int i=0;i<nums.size();i++)
        {
            l = l ? l : 1;
            r = r ? r : 1;

            l = l*nums[i];
            r = r*nums[nums.size()-i-1];

            ans = max({ans,l,r});
        }
        return ans;
    }
};