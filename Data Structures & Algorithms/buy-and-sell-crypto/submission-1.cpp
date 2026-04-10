class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buyI = 0;
        int sellI = 1;
        int maxProf = 0;

        while (sellI < prices.size()) {
            if (prices[sellI] - prices[buyI] > maxProf) {
                maxProf = prices[sellI] - prices[buyI];
            }

            if (prices[sellI] < prices[buyI]) {
                buyI = sellI;
            }
            ++sellI;
        }
        return maxProf;
    }
};
