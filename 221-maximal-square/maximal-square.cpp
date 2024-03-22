class Solution {
public:

    void calculatePrefixSum(vector<vector<int>>&psum)
    {
        int N = psum.size();
        int M = psum[0].size();

        for(int i=0;i<N;i++)
        {
            for(int j=1;j<M;j++)
            {
                psum[i][j] += psum[i][j-1];
            }
        }

        for(int j=0;j<M;j++)
        {
            for(int i=1;i<N;i++)
            {
                psum[i][j] += psum[i-1][j];
            }
        }

    }

    int sumRegion(vector<vector<int>>&psum,int r1,int c1, int r2, int c2)
    {
        int ans = psum[r2][c2];

        if(r1 > 0)
            ans -= psum[r1-1][c2];
        if(c1 > 0)
            ans -= psum[r2][c1-1];
        if(r1 > 0 and c1 > 0)
            ans += psum[r1-1][c1-1];
        
        return ans;
    }
    int calculate(vector<vector<int>>&psum,int i, int j)
    {
        int l = 1 , h = min(psum.size()-i , psum[0].size()-j);
        int ans = 1;
        while(l <= h)
        {
            int mid = l + (h-l)/2;

            int botX = i+mid-1;
            int botY = j+mid-1;

            int sum = sumRegion(psum,i,j,botX,botY);

            if(sum == mid*mid)
            {
                ans = mid*mid;
                l = mid+1;
            }
            else
            {
                h = mid-1;
            }
        }
        return ans;
    }
    int maximalSquare(vector<vector<char>>& matrix) {

        vector<vector<int>>psum(matrix.size(),vector<int>(matrix[0].size(),0));

        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                psum[i][j] = matrix[i][j] - '0';
            }
        }
        calculatePrefixSum(psum);

        int ans = 0;

        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j] == '1')
                    ans = max(ans,calculate(psum,i,j));
            }
        }
        return ans;

    }
};