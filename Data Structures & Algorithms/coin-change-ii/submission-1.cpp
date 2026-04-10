class Solution {
public:
    int decision(int remaining, int index, vector<int>& coins, vector<vector<int>> &dp) {
        if (dp[remaining][index] != -1) return dp[remaining][index];

        if (remaining == 0) {
            dp[remaining][index] = 1;
            return 1;
        }
        // include it
        int res = 0;
        if (remaining >= coins[index]) {
            res += decision(remaining - coins[index], index, coins, dp);
        }
        // not include it
        if (index < coins.size() - 1)
            res += decision(remaining, index + 1, coins, dp);

        dp[remaining][index] = res;
        return res;
    }

    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(amount + 1, vector<int>(coins.size(), -1));
        return decision(amount, 0, coins, dp);
    }
};


/*



*/
