class Solution {
public:
    int operate(vector<vector<int>>& memo, vector<int>& prices, int index, bool buying) {
        if (index >= prices.size()) return 0;
        if (memo[index][buying] != -1) return memo[index][buying];

        int maxProfit = operate(memo, prices, index + 1, buying);
        if (buying) {
            maxProfit = max(maxProfit, operate(memo, prices, index + 1, false) - prices[index]);
        } else {
            maxProfit = max(maxProfit, operate(memo, prices, index + 2, true) + prices[index]);
        }
        memo[index][buying] = maxProfit;
        return memo[index][buying];
    }

    int maxProfit(vector<int>& prices) {
        vector<vector<int>> memo(prices.size() + 1, vector<int>(2, -1));
        return operate(memo, prices, 0, true);
    }
};
