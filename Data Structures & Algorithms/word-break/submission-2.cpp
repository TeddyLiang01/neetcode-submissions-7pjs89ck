class Solution {
public:
    unordered_map<string, bool> dp;
    bool wordBreak(string s, vector<string>& wordDict) {
        if (dp.count(s) > 0) return dp[s];
        bool possible = false;
        for (auto& word : wordDict) {

            if (s == word) {
                dp[s] = true;
                return true;
            }

            if (s.rfind(word, 0) == 0) {
                string subString = s.substr(word.size());
                if (dp.count(subString) == 0) dp[subString] = wordBreak(s.substr(word.size()), wordDict);
                possible = possible || dp[subString];
                if (possible) return true;
            }
        }
        return possible;
    }
};
