class Solution {
public:

    int solve(vector<int>&A,int N)
    {
        int ans = 0;
        for(int i=0;i<N;i++)
        {
            if(A[i] >= N-i)
            {
                ans = max(ans,N-i);
            }
        }
        return ans;
    }
    
    int hIndex(vector<int>& citations) {
        int N = citations.size();
        return solve(citations,N);
        int start = 0;
        int end = N-1;
        int ans = 0;
        while(start <= end)
        {
            int mid = start + (end-start)/2;
            
            if(citations[mid] >= N-mid)
            {
                ans = max(ans,N-mid);
                end = mid-1;
            }
            else
                start = mid + 1;
        }
        return ans;
    }
};