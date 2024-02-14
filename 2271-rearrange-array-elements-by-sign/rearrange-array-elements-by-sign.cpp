class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        
        vector<int>positive;
        vector<int>negative;

        for(int x:nums)
        {
            if(x > 0)
                positive.push_back(x);
            else
                negative.push_back(x);
        }

        vector<int>res;
        for(int i=0;i<positive.size();i++)
        {
            res.push_back(positive[i]);
            res.push_back(negative[i]);
        }

        return res;
    }
};