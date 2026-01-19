class Solution {
public:
    int dSum(int i)
    {
        if(i < 10)
            return i;
        int sum = 0;
        while(i)
        {
            sum += i%10;
            i/=10;
        }
        return sum;
    }
    int countLargestGroup(int n) {
        unordered_map<int, int> hashMap;
        int maxValue = 0;
        for (int i = 1; i <= n; ++i) {
            int digitSum = dSum(i);
            hashMap[digitSum]++;
        }
        for(auto it:hashMap)
        {
            maxValue = max(maxValue,it.second);
        }
        int count = 0;
        for (auto& [_, value] : hashMap) {
            if (value == maxValue) {
                ++count;
            }
        }
        return count;
    }
};