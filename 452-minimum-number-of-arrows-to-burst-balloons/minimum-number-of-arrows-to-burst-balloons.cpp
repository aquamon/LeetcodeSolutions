class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b)
    {
        return a[1] < b[1];
    }
    
    int findMinArrowShots(vector<vector<int>>& points) {
        
        sort(points.begin(),points.end(),cmp);

        vector<int>curr = points[0];

        int arrows = 1;
        int last = points[0][1];

        for(int i=1;i<points.size();i++)
        {
            if(points[i][0] > last)
            {
                arrows++;
                last = points[i][1];
            }
        }
      
        return arrows;
        
    }
};