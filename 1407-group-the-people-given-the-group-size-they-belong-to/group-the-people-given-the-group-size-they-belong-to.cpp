class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        
        unordered_map<int,vector<int>>M;
        vector<vector<int>>ans;
        for(int i=0;i<groupSizes.size();i++)
        {
            M[groupSizes[i]].push_back(i);

            if(M[groupSizes[i]].size() == groupSizes[i])
            {
                ans.push_back(M[groupSizes[i]]);
                M[groupSizes[i]].clear();
            }
                

        }

       

        // for(auto it:M)
        // {
        //     int X = it.first;
        //     int sz = it.second.size();
        //     vector<int> A = it.second;
        //     if(sz <= X)
        //         ans.push_back(it.second);
        //     else
        //     {
        //         vector<int>temp;
        //         int curr_size = 0;
        //         for(int i=0;i<sz;i++)
        //         {
        //             if(curr_size++ < X)
        //                 temp.push_back(A[i]);
        //             else
        //             {
        //                 ans.push_back(temp);
        //                 temp.clear();
        //                 temp.push_back(A[i]);
        //                 curr_size = 1;
        //             }
        //         }
        //         if(curr_size >= 1)
        //             ans.push_back(temp);
                
        //     }
        // }
        

        return ans;
    
    }
};