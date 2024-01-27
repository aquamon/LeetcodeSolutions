class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b)
    {
        return a[0] < b[0];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        
        sort(points.begin(),points.end(),cmp);

        vector<int>curr = points[0];

        int count = 1;
        for(int i=0;i<points.size();i++)
        {
            if(curr[1] < points[i][0])
            {
                curr = points[i];
                count++;
            }
            
                curr[1] = min(curr[1],points[i][1]);
           
        }
      
        return count;
        
    }
};