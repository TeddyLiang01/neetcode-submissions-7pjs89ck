class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int low = 0;
        int high = 0;
        int highest = 0;

        while(high < prices.size()) {
            if (prices[low] > prices[high]) low = high;
            if (prices[high] - prices[low] > highest) highest = prices[high] - prices[low];
            high += 1;
        }
        return highest;
    }
};
