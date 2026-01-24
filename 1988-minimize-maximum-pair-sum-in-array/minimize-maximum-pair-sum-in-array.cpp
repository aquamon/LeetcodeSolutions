class Solution {
public:
    int minPairSum(vector<int>& nums) {

        sort(nums.begin(),nums.end());
        int ans = INT_MIN;

        for(int i=0,j=nums.size()-1;i<j;i++,j--)
        {
            int curr_sum = nums[i]+nums[j];
            if(curr_sum > ans)
            {
                ans = curr_sum;
            } 
        }
        return ans;
        
    }
};