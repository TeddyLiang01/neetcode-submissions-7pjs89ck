class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> minCost(cost.size() + 1, 0);

        for (int i = 2; i <= cost.size(); ++i) {
            minCost[i] = min(cost[i - 1] + minCost[i - 1], cost[i - 2] + minCost[i - 2]);
        }
        return minCost[cost.size()];
    }
};
