class Solution {
public:

    int solve(vector<int> &nums,int K)
    {
        int count = 0;
        unordered_map<int,int>M;
        for(int i=0,j=0;j<nums.size();j++)
        {
            M[nums[j]]++;
             while(M.size() > K)
                {
                    M[nums[i]]--;
                    if(M[nums[i]] == 0)
                        M.erase(nums[i]);
                    i++;
                }
                count += (j-i+1);
            
        }

        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
        return solve(nums,k) - solve(nums,k-1);
    }
};