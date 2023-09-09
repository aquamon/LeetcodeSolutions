class Solution {
public:
    int maxJump(vector<int>& stones) {
        
        int ans = stones[1];

        for(int i=0;i<stones.size()-2;i++)
        {
            ans = max(ans,abs(stones[i] - stones[i+2]));
        }
        return ans;
        
    }
};