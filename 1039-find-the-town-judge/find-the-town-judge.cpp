class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        if(trust.size() < 1 and n==1)
            return 1;
        unordered_map<int,int> M ;
        unordered_map<int,int> vote;
        for(int i=0;i<trust.size();i++)
        {
            int a = trust[i][0];
            int b = trust[i][1];

            M[a]++;
            vote[b]++;
        }

        for(int i=1;i<=n;i++)
        {
            if(M.find(i) == M.end() and vote.find(i) != vote.end() and vote[i] == n-1)
                return i;
        }
        return -1;
    }
};