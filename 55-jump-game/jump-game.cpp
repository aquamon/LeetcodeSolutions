class Solution {
public:

    bool solve(int idx,int N,vector<int>&nums,vector<int>&isVis)
    {
        
        if(idx == N-1)
            return true;
        if(idx >= N)
            return  false;
        if(isVis[idx] != -1)
            return isVis[idx];
        
        int curr_step = nums[idx];

        for(int i=1;i<nums.size() and i<=curr_step;i++)
        {
            isVis[idx+i] = solve(idx+i,N,nums,isVis);
            if(isVis[idx+i] == 1)
            {

              return isVis[idx+i];
            }
        }
        return isVis[idx] = false;
    }
    bool canJump(vector<int>& nums) {
        
        int n = nums.size();
        vector<int>isVis(nums.size(),-1);
        return solve(0,n,nums,isVis);
    }
};