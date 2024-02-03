class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        
        vector<int>answer;

        string buffer = "123456789";
        string start = to_string(low);
        string finish = to_string(high);

        for(int i=start.size();i<=finish.size();i++)
        {
            for(int j=0;j<=9-i;j++)
            {
                string curr = buffer.substr(j,i);
                int num = stoi(curr);

                if(num >= low and num <= high)
                    answer.push_back(num);
                if(num > high)
                    break;
                
            }
        }

        return answer;


    }
};