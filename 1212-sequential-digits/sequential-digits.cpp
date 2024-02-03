class Solution {
public:

    vector<int>res;

    void dfs(int i,int low,int high)
    {
        if(i >=low and i <= high)
            res.push_back(i);
        
        if(i > high or i%10 == 9)
            return;
        
        dfs((i*10)+(i%10 + 1),low,high);
    }

    vector<int> sequentialDigits(int low, int high) {
        

        for(int i=1;i<=9;i++)
        {
            dfs(i,low,high);
        }

        sort(res.begin(),res.end());
        return res;

    }
};