class Solution {
public:
    int climbStairs(int n) {
        int memo[n + 1] = {0};
        memo[1] = 1;
        memo[2] = 2;
        return climbRecurse(n, memo);
    }

    int climbRecurse(int n, int* memo) {
        if (memo[n] != 0) {
            return memo[n];
        }

        if (memo[n - 1] == 0) {
            memo[n - 1] = climbRecurse(n - 1, memo);
        }
        if (memo[n - 2] == 0) {
            memo[n - 2] = climbRecurse(n - 2, memo);
        }

        memo[n] = memo[n - 1] + memo[n - 2];
        return memo[n];
    }
};
