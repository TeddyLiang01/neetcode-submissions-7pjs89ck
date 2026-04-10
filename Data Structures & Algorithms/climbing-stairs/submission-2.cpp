class Solution {
public:
    int climbStairs(int n) {
        vector<int> preCalcSteps;
        preCalcSteps.push_back(1);
        preCalcSteps.push_back(2);
        while (preCalcSteps.size() < n) {
            preCalcSteps.push_back(preCalcSteps.at(preCalcSteps.size() - 1) + preCalcSteps.at(preCalcSteps.size() - 2));
        }

        return preCalcSteps.at(n - 1);
    }
};
