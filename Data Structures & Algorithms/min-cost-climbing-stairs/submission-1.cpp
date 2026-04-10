class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        return findCost(cost.size(), cost);
    }

    int findCost(int floor, vector<int>& cost) {
        if (floor == 0) {
            return 0;
        } if (floor == 1) {
            return 0;
        }

        int oneDown = findCost(floor - 1, cost) + cost[floor - 1];
        int twoDown = findCost(floor - 2, cost) + cost[floor - 2];
        return min(oneDown, twoDown);
    }
};

// 
// 1 2 3 4
// 0 0 1 2
