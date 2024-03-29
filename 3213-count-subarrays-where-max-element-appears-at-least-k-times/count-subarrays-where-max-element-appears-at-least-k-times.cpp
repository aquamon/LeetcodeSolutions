class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        
        int MAX = *max_element(nums.begin(),nums.end());

        long long ans = 0;

        int i=0 , j = 0;

        unordered_map<int,int>M;

        while(j < nums.size())
        {
            M[nums[j]]++;

            while(M[MAX] >= k)
            {
                ans = ans + nums.size()-j;
                M[nums[i]]--;
                i++;
            }
            j++;
        }
        return ans;

    }
};