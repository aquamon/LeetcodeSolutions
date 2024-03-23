class Solution {
public:

    int calculate(vector<int> nums1, vector<int> nums2)
    {
        int sum = 0;
        for(int i=0;i<nums1.size();i++)
        {
            sum += nums1[i];
            nums1[i] = nums2[i]-nums1[i];
        }

        int ans = 0;

        nums1[0] = nums1[0] < 0 ? 0 : nums1[0];

        for(int i=1;i<nums1.size();i++)
        {
            nums1[i] += nums1[i-1];

            ans = max(ans,nums1[i]);
            
            if(nums1[i] < 0)
                nums1[i] = 0;
        }

        return sum + ans;
    }
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        
        return max(calculate(nums1,nums2) , calculate(nums2,nums1));
    }
};