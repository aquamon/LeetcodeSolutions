class Solution {
public:

    vector<int> findAna(string S)
    {
        vector<int> freq(26,0);
        for(int i=0;i<S.length();i++)
            freq[S[i] - 'a']++;
        return freq;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        map<vector<int>,vector<string>>M;

        for(string S : strs)
        {
            vector<int> ana = findAna(S);
            M[ana].push_back(S);
        }

        vector<vector<string>>ans;

        for(auto i : M)
        {
            ans.push_back(i.second);
        }

        return ans;
    }
};