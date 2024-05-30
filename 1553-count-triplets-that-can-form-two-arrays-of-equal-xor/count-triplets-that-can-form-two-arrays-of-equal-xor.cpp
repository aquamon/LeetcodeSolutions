class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int res = 0;
        for(int i=0;i<arr.size();i++)
        {
            int X = arr[i];
            for(int j=i+1;j<arr.size();j++)
            {
                X ^= arr[j];
                if(X == 0)
                    res += (j-i);
            }
        }
        return res;
    }
};