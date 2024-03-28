class Solution {
    public int maxSubarrayLength(int[] nums, int k) {
        
        int ans = 0;
        HashMap<Integer,Integer> HM = new HashMap<>();
        for(int i=0,j=0;j<nums.length;)
        {
            if(HM.getOrDefault(nums[j],0) < k)
            {
               HM.put(nums[j],HM.getOrDefault(nums[j],0)+1);
               ans = Math.max(ans,j-i+1);
               j++;
            }
            else
            {
                HM.put(nums[i],HM.get(nums[i])-1);
                i++;
            }
        }
        return ans;
    }
}