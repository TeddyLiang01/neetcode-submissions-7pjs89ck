class Solution {
public:
    int recurse(unordered_map<string, int>& memo, vector<int>& nums, int index, int curSum, const int target) {
        if (index == nums.size()) {
            if (curSum == target) return 1;
            return 0;
        }
        string key = to_string(index) + "-" + to_string(curSum);
        if (memo.count(key) > 0) return memo[key];
        memo[key] = recurse(memo, nums, index + 1, curSum + nums[index], target) + recurse(memo, nums, index + 1, curSum - nums[index], target);
        return memo[key];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<string, int> memo;
        return recurse(memo, nums, 0, 0, target);
    }
};


