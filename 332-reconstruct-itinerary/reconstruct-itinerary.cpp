class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        
        unordered_map<string,priority_queue<string,vector<string>,greater<string>>> M ;

        for(vector<string> R : tickets)
        {
            M[R[0]].push(R[1]);
        }
        stack<string>S;

        S.push("JFK");

        vector<string>ans;

        while(!S.empty())
        {
            string curr = S.top();

            if(M.find(curr) != M.end() and M[curr].size() != 0)
            {
                S.push(M[curr].top());
                M[curr].pop();
            }
            else
            {
                ans.push_back(curr);
                S.pop();
            }
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};