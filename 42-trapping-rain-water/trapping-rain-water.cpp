class Solution {
public:

    vector<int> computePrefixMax(vector<int>&arr)
    {
        vector<int>ans(arr.size(),INT_MIN);
        ans[0] = arr[0];
        for(int i=1;i<arr.size();i++)
        {
            ans[i] = max(ans[i-1],arr[i]);
        }

        return ans;
    }

    vector<int> computeSuffixMax(vector<int>&arr)
    {
        vector<int>ans(arr.size(),INT_MIN);
        ans[arr.size()-1] = arr[arr.size()-1];
        for(int i=arr.size()-2;i>=0;i--)
        {
            ans[i] = max(ans[i+1],arr[i]);
        }

        return ans;

    }
    int trap(vector<int>& height) {
        
        if(height.size() < 3)
            return 0;
        vector<int> PrefixMax = computePrefixMax(height);
        vector<int> SuffixMax = computeSuffixMax(height);

        int ans = 0;
        for(int i=1;i<height.size()-1;i++)
        {
            int X = min(PrefixMax[i],SuffixMax[i]);
            if(X-height[i] > 0)
                ans += X-height[i];
        }
        return ans;




    }
};