class Solution {
public:
    void findCombinations(vector<int>& candidates, vector<vector<int>>& result, unordered_map<int, int>& lastOccur, vector<int> current, int remaining, int index) {
        if (remaining == 0) {
            result.push_back(current);
            return;
        }
        if (index == candidates.size()) return;
        
        findCombinations(candidates, result, lastOccur, current, remaining, lastOccur[candidates[index]] + 1);
        if (candidates[index] <= remaining) {
            current.push_back(candidates[index]);
            findCombinations(candidates, result, lastOccur, current, remaining - candidates[index], index + 1);
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        unordered_map<int, int> lastOccur;

        for (int i = 0; i < candidates.size(); ++i) {
            lastOccur[candidates[i]] = i;
        }

        vector<vector<int>> result;
        vector<int> current;
        findCombinations(candidates, result, lastOccur, current, target, 0);
        return result;
    }
};
