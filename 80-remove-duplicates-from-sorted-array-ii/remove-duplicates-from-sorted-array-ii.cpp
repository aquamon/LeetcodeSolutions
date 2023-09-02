class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
      int i=0 , j = 1;
    
      int count = 0;
      while(j < nums.size())
      {
          if(nums[j] == nums[j-1])
          {
              count++;
          }
          else
          {
             count = 0;
          }

          if(count > 1)
          {
              j++;
          }
          else
          {
              nums[i+1] = nums[j];
              i++;
              j++;
          }
          
      }
      return i+1;

      
        
    }
};