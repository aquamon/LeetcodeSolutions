class Solution {
public:
    int maxArea(vector<int>& height) {

       int i=0, j =height.size()-1;

       int ans = 0;

       while(i<j)
       {
           int curr = min(height[i],height[j]);
           int diff = j-i;
           int curr_ans = curr*diff;

           ans = max(ans,curr_ans);

           if(height[i] <= height[j])
           {
               i++;
           }
           else
           {
               j--;
           }
       }
       return ans; 
    }
};