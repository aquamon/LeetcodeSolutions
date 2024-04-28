class Solution {
public:
    pair<int,int> getWindow(vector<int> &customers, vector<int> &grumpy, int K)
    {
        int max_sum = 0 , sum = 0;
        int x = 0 , y = K-1;
        for(int i=0;i<K;i++)
        {
            if(grumpy[i] == 1)
                sum += customers[i];
        }
        max_sum = sum;


        for(int i=0,j=K; i < customers.size()-K+1 and j < customers.size() ; i++ , j++)
        {
            if(grumpy[j] == 1)
            {
                sum += customers[j];
            }
            if(grumpy[i] == 1)
            {
                sum -= customers[i];
            }

            if(sum > max_sum)
            {
                max_sum = sum;
                x = i+1;
                y = j;
            }
        }

        return {x,y};
    }
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        
        pair<int,int> window = getWindow(customers,grumpy,minutes);

        int i = window.first , j = window.second;

        for(;i<=j;i++)
            grumpy[i] = 0;
        
        int answer = 0;

        for(int i=0;i<customers.size();i++)
        {
            if(grumpy[i] == 0)
                answer += customers[i];
        }

        return answer;
    }
};