class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        
        vector<int>ans , indx_a , indx_b;

        int x = s.size() , y = a.size() , z = b.size();

        for(int i=0;i<=x-y;i++)
        {
            if(s.substr(i,y) == a)
            {
                indx_a.push_back(i);
            }
        }
        for(int i=0;i<=x-z;i++)
        {
            if(s.substr(i,z) == b)
            {
                indx_b.push_back(i);
            }
        }

        for(int i=0;i<indx_a.size();i++)
        {
            for(int j=0;j<indx_b.size();j++)
            {
                if(abs(indx_a[i] - indx_b[j]) <= k)
                {
                    ans.push_back(indx_a[i]);
                    break;
                }
            }
        }

        sort(ans.begin(),ans.end());
        return ans;
    }
};