class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        
        int M = 1000000007;

        vector<int>PSE(arr.size(),-1);
        vector<int>NSE(arr.size(),arr.size());

        stack<int>S;
        S.push(arr.size()-1);

        for(int i=arr.size()-2;i>=0;i--)
        {
            while(!S.empty() and arr[i] <= arr[S.top()])
            {
                PSE[S.top()] = i; 
                S.pop();
            }
            S.push(i);
        }
        while(!S.empty())
        {
            PSE[S.top()] = -1;
            S.pop();
        }

        S.push(0);

        for(int i=1;i<arr.size();i++)
        {
            while(!S.empty() and arr[i] < arr[S.top()])
            {
                NSE[S.top()] = i;
                S.pop();
            }
            S.push(i);
        }

        while(!S.empty())
        {
            NSE[S.top()] = arr.size();
            S.pop();
        }

        long long int ans = 0;
        for(int i=0;i<arr.size();i++)
        {
            int start = i-PSE[i];
            int end = NSE[i] - i;

            long long int contribution = (start%M*end%M)%M;

            long long int curr_ans = (contribution%M*arr[i]%M)%M;

            ans = (ans%M + curr_ans%M)%M;

        }

        return ans%M;
    }
};