class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lowIndex = 0;
        int profit = 0;

        for (int i = 0; i < prices.size(); ++i) {
            if (prices[lowIndex] > prices[i]) {
                lowIndex = i;
            }
            if (prices[i] - prices[lowIndex] > profit) {
                profit = prices[i] - prices[lowIndex];
            }
        }
        return profit;
        
    }
};
