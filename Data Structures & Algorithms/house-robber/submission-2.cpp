class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        vector<int> maxPerLength(nums.size() + 1, 0);
        maxPerLength[1] = nums[0];
        for (int i = 2; i <= nums.size(); ++i) {
            maxPerLength[i] = max(maxPerLength[i - 1], maxPerLength[i - 2] + nums[i - 1]);
        }

        return maxPerLength[nums.size()];
    }
};
