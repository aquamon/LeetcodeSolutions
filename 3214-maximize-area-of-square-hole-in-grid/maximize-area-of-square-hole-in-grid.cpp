class Solution {
public:
    int consecutive(vector<int> &A)
    {
        int conse_X = 1;
         for(int i=0,j=1;j<A.size() and i<A.size();)
        {
           if(A[j] == A[j-1]+1)
           {
            conse_X = max(conse_X , j-i+1 );
            j++;
           }
           else
           {
            conse_X = max(conse_X , j-i);
            i=j;
            j=i+1;
           }
        }
        return conse_X;

    }
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {

        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());

        int X_con = consecutive(hBars);
        int Y_con = consecutive(vBars);
        int answer = min(X_con,Y_con)+1;
        return answer * answer;
       

        
    }
};