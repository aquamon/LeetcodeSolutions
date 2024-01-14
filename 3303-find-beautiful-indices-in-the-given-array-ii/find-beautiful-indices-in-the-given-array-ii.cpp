class Solution {
public:
vector<int> rabin_karp(string const& s, string const& t) {
    const int p = 31; 
    const int m = 1e9 + 9;
    int S = s.size(), T = t.size();

    vector<long long> p_pow(max(S, T)); 
    p_pow[0] = 1; 
    for (int i = 1; i < (int)p_pow.size(); i++) 
        p_pow[i] = (p_pow[i-1] * p) % m;

    vector<long long> h(T + 1, 0); 
    for (int i = 0; i < T; i++)
        h[i+1] = (h[i] + (t[i] - 'a' + 1) * p_pow[i]) % m; 
    long long h_s = 0; 
    for (int i = 0; i < S; i++) 
        h_s = (h_s + (s[i] - 'a' + 1) * p_pow[i]) % m; 

    vector<int> occurrences;
    for (int i = 0; i + S - 1 < T; i++) {
        long long cur_h = (h[i+S] + m - h[i]) % m;
        if (cur_h == h_s * p_pow[i] % m)
            occurrences.push_back(i);
    }
    return occurrences;
}
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        
        vector<int> ans, indices_a, indices_b;

        int x = s.size() , y = a.size() , z = b.size();

        // for(int i=0;i<=x-y;i++)
        // {
        //     if(s.substr(i,y) == a)
        //     {
        //         indices_a.push_back(i);
        //     }
        // }
        // for(int i=0;i<=x-z;i++)
        // {
        //     if(s.substr(i,z) == b)
        //     {
        //         indices_b.push_back(i);
        //     }
        // }

        indices_a = rabin_karp(a,s);
        indices_b = rabin_karp(b,s);

        int i=0;
        int j=0;

        while(i < indices_a.size() and j < indices_b.size())
        {
            if(abs(indices_a[i] - indices_b[j]) <= k)
            {
                ans.push_back(indices_a[i]);
                i++;
            }
            else
            {
                if(indices_a[i] < indices_b[j])
                {
                    i++;
                }
                else
                {
                    j++;
                }
            }
        }
        return ans;


    }
};