class Solution {
public:
    bool checkSubstring(string substring, unordered_map<string, int> wordsHashMap, unordered_set<string>& memo, int wordLength)
    {
        if (memo.contains(substring))
            return true;
            
        for (int j = 0; j < substring.size(); j += wordLength)
        {
            string word = substring.substr(j, wordLength);

            if (!wordsHashMap.contains(word))
                return false;

            if (wordsHashMap[word] <= 0)
                return false;

            wordsHashMap[word]--;
        }

        memo.insert(substring);

        return true;
    }

    vector<int> findSubstring(string s, vector<string>& words) {
        int wordCount = words.size();
        int wordLength = words[0].size();

        int wordsLength = wordCount * wordLength;

        unordered_map<string, int> wordsHashMap;
        for (const auto& word : words)
            wordsHashMap[word]++;

        unordered_set<string> memo;

        vector<int> answer;

        for (int i = 0; i < s.size() - wordsLength + 1; i++)
        {
            if (checkSubstring(s.substr(i, wordsLength), wordsHashMap, memo, wordLength))
                answer.push_back(i);
        }

        return answer;
    }
};