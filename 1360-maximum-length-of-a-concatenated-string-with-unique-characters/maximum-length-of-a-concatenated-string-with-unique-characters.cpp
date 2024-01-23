class Solution {
public:
    bool check(string S)
    {
        int freq[26] = {0};
        for(char x:S)
            freq[x-'a']++;
        for(int x:freq)
        {
            if(x > 1)
                return false;
        }
        return true;
    }
    int solve(int idx,int N,vector<string>&S,string curr)
    {
        if(idx >= N)
            return curr.size();
        
        string C = curr+S[idx];
        int take = 0 , untake = 0;
        if(check(C))
            take = solve(idx+1,N,S,C);
        
        if(check(curr))
            untake = solve(idx+1,N,S,curr);

        return max(take,untake);    
        
    }
    int maxLength(vector<string>& arr) {
        
        string curr = "";
        return solve(0,arr.size(),arr,curr);
    }
};