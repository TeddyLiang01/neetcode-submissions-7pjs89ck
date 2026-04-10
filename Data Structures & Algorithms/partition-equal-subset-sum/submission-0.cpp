class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (auto n : nums) sum += n;

        if (sum % 2 == 1) return false;
        int target = sum / 2;

        unordered_set<int> dp;
        dp.insert(nums[0]);
        for (int i = 1; i < nums.size(); ++i) {
            for (auto s : dp) {
                if (s > target) continue;
                if (s + nums[i] == target) return true;
                dp.insert(s + nums[i]);
            }
        }
        return dp.count(target) == 1;
    }
};
