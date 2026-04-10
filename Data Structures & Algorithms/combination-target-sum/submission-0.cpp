class Solution {
public:
    void dfs(int index, vector<int> curNums, int curTotal, vector<vector<int>> &result, vector<int> &nums, int &target) {
        if (curTotal == target) {
            result.push_back(curNums);
            return;
        }

        if (index >= nums.size() || curTotal > target) return;

        curNums.push_back(nums[index]);
        dfs(index, curNums, curTotal + nums[index], result, nums, target);
        curNums.pop_back();
        dfs(index + 1, curNums, curTotal, result, nums, target);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        vector<int> empty;
        dfs(0, empty, 0, result, nums, target);
        return result;
    }
};
