class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        
        vector<string>answer(score.size());

        vector<pair<int,int>> ref ;

        for(int i=0;i<score.size();i++)
        {
            ref.push_back({score[i],i});
        }

        sort(ref.begin(),ref.end());

        reverse(ref.begin(),ref.end());

        

        for(int i=0;i<ref.size();i++)
        {
            if(i == 0)
            {
                answer[ref[i].second] = "Gold Medal";
            }
            else if(i == 1)
            {
                answer[ref[i].second] = "Silver Medal";        
            }
            else if(i == 2)
            {
                 answer[ref[i].second] = "Bronze Medal";   
            }
            else
            {
                 answer[ref[i].second] = to_string(i+1);   
            }
        }

        return answer;


    }
};