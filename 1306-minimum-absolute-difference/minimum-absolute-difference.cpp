class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        
        vector<vector<int>>res;

        sort(arr.begin(),arr.end());

        int min_diff = INT_MAX;
        for(int i=1;i<arr.size();i++)
        {
            int curr = abs(arr[i]-arr[i-1]);

            min_diff = min(min_diff,curr);
        }


        for(int i=1;i<arr.size();i++)
        {
            int curr = abs(arr[i]-arr[i-1]);

            if(curr == min_diff)
            {
                res.push_back({arr[i-1],arr[i]});
            }
        }

        return res;
    }
};