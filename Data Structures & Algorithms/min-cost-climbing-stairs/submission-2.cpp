class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> eachFloorCost;
        eachFloorCost.reserve(cost.size());
        eachFloorCost[0] = 0;
        eachFloorCost[1] = 0;

        for (int i = 2; i <= cost.size(); ++i) {
            int oneDown = eachFloorCost[i - 1] + cost[i - 1];
            int twoDown = eachFloorCost[i - 2] + cost[i - 2];
            
            eachFloorCost[i] = min(oneDown, twoDown);
        }
        return eachFloorCost[cost.size()];
    }
};

// 
// 1 2 3 4
// 0 0 1 2
