class Solution {
public:
    bool static cmp(int a,int b)
    {
        int A = __builtin_popcount(a);
        int B = __builtin_popcount(b);

        if(A == B)
        {
            return a < b;
        }
       
        return A < B;
    }
    vector<int> sortByBits(vector<int>& arr) {
        
        sort(arr.begin(),arr.end(),cmp);
        return arr;
    }
};