class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        vector<int> dp(amount + 1, -1);

        for (int i = 0; i <= amount; ++i) {
            int curBest = INT_MAX;
            for (auto &c : coins) {
                int diff = i - c;
                if (diff == 0) curBest = 1;
                else if (diff > 0 && dp[diff] != -1) {
                    if (1 + dp[diff] < curBest) curBest = 1 + dp[diff];
                }
            }
            if (curBest != INT_MAX) dp[i] = curBest;
            else dp[i] = -1;
        }

        return dp[amount];
    }
};
