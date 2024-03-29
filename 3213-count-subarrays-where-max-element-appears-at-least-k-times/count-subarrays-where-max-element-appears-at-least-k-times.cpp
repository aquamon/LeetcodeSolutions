class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        
        int MAX = *max_element(nums.begin(),nums.end());

        long long ans = 0 , start = 0;

        for(int end = 0; end < nums.size();end++)
        {
            if(nums[end] == MAX)
            {
                k--;
            }
            while(!k)
            {
                if(nums[start] == MAX)
                {
                    k++;
                }
                start++;
            }
            ans += start;
        }
        return ans;

    }
};