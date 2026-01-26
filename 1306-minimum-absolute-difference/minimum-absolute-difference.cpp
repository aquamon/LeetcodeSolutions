class Solution {
public:
    
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        
        sort(arr.begin(),arr.end());

        int min_abs_diff = INT_MAX;
        for(int i=1;i<arr.size();i++)
        {
            min_abs_diff = min(min_abs_diff,arr[i]-arr[i-1]);
        }
        unordered_map<int,int>HM;
        for(int i=0;i<arr.size();i++)
        {
            HM[arr[i]]++;
        }

        vector<vector<int>> result;

        for(int i=0;i<arr.size();i++)
        {
            int curr = arr[i];

            if(HM.find(curr-min_abs_diff) != HM.end())
            {
                result.push_back({curr,curr-min_abs_diff});
                HM.erase(curr-min_abs_diff);
            }
        }

        
        sort(result.begin(),result.end());
        
        
       
        for(int i=0;i<result.size();i++)
        {
            sort(result[i].begin(),result[i].end());
        }
        return result;
    }
};