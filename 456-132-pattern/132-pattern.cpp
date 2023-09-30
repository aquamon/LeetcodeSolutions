class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        
        unordered_map<int,int>M;

        for(auto it:nums)
            M[it] = INT_MAX;
        int MIN = INT_MAX;

        for(int i=0;i<nums.size();i++)
        {
            // for(int j=0;j<i;j++)
            // {
            //     if(nums[j] < nums[i])
            //         M[nums[i]] = min(nums[j],M[nums[i]]);
            // }

            MIN = min(nums[i],MIN);

            if(nums[i] != MIN)
                M[nums[i]] = MIN;
        }

        stack<int>ST;

        for(int i=nums.size()-1;i>=0;i--)
        {
            if(nums[i] > M[nums[i]])
            {
                while(!ST.empty() and ST.top() <= M[nums[i]])
                    ST.pop();
                if(!ST.empty() and ST.top() < nums[i])
                    return true;
                ST.push(nums[i]);
            }
        }
        return false;
    }
};