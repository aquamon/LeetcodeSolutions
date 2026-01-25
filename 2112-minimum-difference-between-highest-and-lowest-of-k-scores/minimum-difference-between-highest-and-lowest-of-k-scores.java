class Solution {
    public int minimumDifference(int[] nums, int k) {
        
        if(k<2)
            return 0;
        Arrays.sort(nums);
        
        int ans = Integer.MAX_VALUE;

        for(int i=0;i<nums.length;i++)
        {
            int left_idx = i;
            int right_idx = i+k-1;
            if(right_idx < nums.length)
            {
                ans = Math.min(ans,nums[right_idx]-nums[left_idx]);
            }
        }
        return ans;
        
    }
}