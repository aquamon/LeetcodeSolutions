class Solution {
public:
    
    
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int>M;

        for(int x : arr)
            M[x]++;
        
       
        // vector<pair<int,int>>VEC;

        // for(auto it:M)
        //     VEC.push_back({it.second , it.first});
        
        // sort(VEC.begin(),VEC.end());

        // for(int i=0;i<VEC.size();i++)
        // {
        //     if(VEC[i].first < k)
        //         k -= VEC[i].first;
        //     else if(VEC[i].first == k)
        //         return VEC.size()-i-1;
        //     else
        //         return VEC.size()-i;

        // }
        
        // return -1;

        priority_queue<int,vector<int>,greater<int>> min_heap;

        for(auto it:M)
            min_heap.push({it.second});
        

        while(!min_heap.empty() and k > 0)
        {
            int x = min_heap.top();
            min_heap.pop();
            k-=x;
            
            
        }
        if(k == 0)
                return min_heap.size();
          
                return min_heap.size()+1;
       
   

    }
};