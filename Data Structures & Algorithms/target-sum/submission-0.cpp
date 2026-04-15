class Solution {
public:
    int recurse(vector<int>& nums, int index, int curSum, const int target) {
        if (index == nums.size()) {
            if (curSum == target) return 1;
            return 0;
        }
        return recurse(nums, index + 1, curSum + nums[index], target) + recurse(nums, index + 1, curSum - nums[index], target);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return recurse(nums, 0, 0, target);
    }
};


