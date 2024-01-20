class Solution {
public:
    string reverseWords(string s) {
         
         vector<string> res;

         string curr = "";   
         for(int i=0;i<s.length();i++)
         {
             if(isspace(s[i]) and curr == "")
                continue;
             if(isspace(s[i]) and curr != "")
             {
                 res.push_back(curr);
                 curr = "";
             }
            else
             curr+=s[i];


         }
         if(curr != "")
            res.push_back(curr);
        
        reverse(res.begin(),res.end());
        
        string ans = "";
        for(string s:res)
        {
            ans += s;
            ans += " ";

        }
        ans.pop_back();
        return ans;
    }
};