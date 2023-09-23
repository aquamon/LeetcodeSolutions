class Solution {
public:

    bool static cmp(string &S, string &T){
        return S.length() < T.length();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),cmp);
        unordered_map<string,int>M;
        int ans = 0;
        for(int i=0;i<words.size();i++)
        {
            M[words[i]] = 1;

            for(int j=0;j<words[i].size();j++)
            {
                string temp = "";
                for(int k=0;k<words[i].size();k++)
                {
                    if(k!=j)
                        temp += words[i][k];
                }

                if(M.find(temp) != M.end())
                {
                    M[words[i]] =  max(M[words[i]],M[temp]+1);

                }                
                
            
            }
            ans = max(ans,M[words[i]]);
            
        }

        return ans;
    }
};