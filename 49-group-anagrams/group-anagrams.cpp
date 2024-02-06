class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>>ans;

        unordered_map<string,vector<string>>M;
        for(string s : strs)
        {
            string curr = s;
            sort(curr.begin(),curr.end());
            M[curr].push_back(s);
        }

        for(auto it:M)
        {
            ans.push_back(it.second);
        }

        return ans;
    }
};