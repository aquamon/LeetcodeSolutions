class Solution {
public:
    int largestInteger(int num) {

       vector<int>odd;
       vector<int>even;
       vector<char>idx;
       while(num > 0)
       {
         int digit = num%10;
         
         if(digit&1)
         {
            odd.push_back(digit);
            idx.push_back('o');
         }
         else
         {
            even.push_back(digit);
            idx.push_back('e');
         }
         num /= 10;
       }

       sort(even.rbegin(),even.rend());
       sort(odd.rbegin(),odd.rend());
       int odd_i = 0;
       int even_i = 0;
       reverse(idx.begin(),idx.end());


       string ans = "";
       for(int i=0;i<idx.size();i++)
       {
        if(idx[i] == 'o')
        {
            ans.push_back(odd[odd_i++]+'0');
        }
        else
        {
            ans.push_back(even[even_i++]+'0');
        }
       }
       return stoi(ans);


    }
};