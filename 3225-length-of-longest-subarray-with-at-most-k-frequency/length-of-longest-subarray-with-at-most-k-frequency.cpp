class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        
       
        unordered_map<int,int>M;
        int ans = 0 , start = 0;
        for(int i=0;i<nums.size();i++)
        {
            M[nums[i]]++;

            while(M[nums[i]] > k)
                M[nums[start++]]--;
            
            ans = max(ans,i-start+1);
        }
        return ans;
    }
};