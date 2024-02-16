class Solution {
public:
    
    bool static cmp(int x,int y)
    {
        return x<y;
    }
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int>M;

        for(int x : arr)
            M[x]++;
        
       
        vector<pair<int,int>>VEC;

        for(auto it:M)
            VEC.push_back({it.second , it.first});
        
        sort(VEC.begin(),VEC.end());

        for(int i=0;i<VEC.size();i++)
        {
            if(VEC[i].first < k)
                k -= VEC[i].first;
            else if(VEC[i].first == k)
                return VEC.size()-i-1;
            else
                return VEC.size()-i;

        }
        
        return -1;

    }
};