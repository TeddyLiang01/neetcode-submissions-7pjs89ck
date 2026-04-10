class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for (int i = 0; i < n; ++i) {
            dp[m - 1][i] = 1;
        }

        for (int row = m - 2; row >= 0; --row) {
            for (int column = n - 1; column >= 0; --column) {
                if (column < n - 1) {
                    dp[row][column] = dp[row + 1][column] + dp[row][column + 1];
                } else {
                    dp[row][column] = dp[row + 1][column];
                }
            }
        }
        return dp[0][0];
    }
};
