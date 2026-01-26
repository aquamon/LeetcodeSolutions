class Solution {
public:
    
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        
        sort(arr.begin(),arr.end());

        int min_abs_diff = INT_MAX;
        for(int i=1;i<arr.size();i++)
        {
            min_abs_diff = min(min_abs_diff,arr[i]-arr[i-1]);
        }
        
        vector<vector<int>>answer;
        for(int i=1;i<arr.size();i++)
        {
            int curr_diff = arr[i]-arr[i-1];
            if(curr_diff == min_abs_diff)
                answer.push_back({arr[i-1],arr[i]});

        }

        return answer;
    }
};