class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int ans = nums[0] , start = 0 , end = 0 , s = 0;

        nums[0] = nums[0] < 0 ? 0 : nums[0];

        for(int i=1;i<nums.size();i++)
        {
            nums[i] += nums[i-1];

            if(nums[i] > ans)
            {
                ans = nums[i];
                end = i;
                start = s;
            }
            if(nums[i] < 0)
            {
                nums[i] = 0;
                s = i+1;
            }
        }
        cout<<start<<"---"<<end<<endl;
        return ans;
    }
};