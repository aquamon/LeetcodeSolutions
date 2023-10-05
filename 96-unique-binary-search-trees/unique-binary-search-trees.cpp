class Solution {
public:
    int numTrees(int n) {
        
        
        vector<int>CAT(n+1,0);
        CAT[1] = 1;
        CAT[0] = 1;
        for(int i=2;i<=n;i++)
        {
            
            for(int j=1;j<=i;j++)
            {
                CAT[i] += CAT[j-1]*CAT[i-j];
            }
            
        }

        return CAT[n];
    }
};