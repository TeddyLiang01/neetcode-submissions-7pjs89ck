class Solution {
public:
    bool dfs(vector<vector<int>> &dp, string &s1, string &s2, string &s3, int index1, int index2) {
        if (index1 == s1.size() && index2 == s2.size()) return true;
        if (dp[index1][index2] != -1) {
            if (dp[index1][index2] == 0) return false;
            return true;
        }

        int res = 0;

        if (index1 < s1.size() && s1[index1] == s3[index1 + index2] && dfs(dp, s1, s2, s3, index1 + 1, index2)) res = 1;
        if (index2 < s2.size() && s2[index2] == s3[index1 + index2] && dfs(dp, s1, s2, s3, index1, index2 + 1)) res = 1;
        dp[index1][index2] = res;
        if (res == 0) return false;
        return true;

    }

    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) return false;
        vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, -1));
        return dfs(dp, s1, s2, s3, 0, 0);
    }
};
