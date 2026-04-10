class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        //find the min cost of taking a step from 0 or 1

        int floorCost[cost.size()];
        floorCost[cost.size() - 1] = cost.back();
        floorCost[cost.size() - 2] = cost[cost.size() - 2];
        for (int i = cost.size() - 3; i >= 0; --i) {
            int oneDown = floorCost[i + 1];
            int twoDown = floorCost[i + 2];
            if (oneDown < twoDown) {
                floorCost[i] = cost[i] + floorCost[i + 1];
            } else {
                floorCost[i] = cost[i] + floorCost[i + 2];
            }
        }

        return floorCost[0] > floorCost[1] ? floorCost[1] : floorCost[0];
    }
};
