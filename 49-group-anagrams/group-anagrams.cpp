class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string,vector<string>>M;

        for(string x:strs)
        {
            string curr = x;
            sort(curr.begin(),curr.end());
            M[curr].push_back(x);
        }

        vector<vector<string>>res;

        for(auto it:M)
            res.push_back(it.second);
        
        return res;
    }
};