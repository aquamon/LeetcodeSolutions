class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        
        long long ans = 0;

        int MAX = *max_element(nums.begin(),nums.end());
        int count = 0;
        for(int i=0,j=0;j<nums.size();j++)
        {
            if(nums[j] == MAX)
            {
                count++;
            }

            while(count == k)
            {
                if(nums[i] == MAX)
                    count--;
                i++;
            }

            ans += i;

        }

        return ans;
    }
};