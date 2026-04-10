class Solution {
public:
    int recurse(vector<int>& nums, int high, int index) {
        if (index == nums.size()) return 0;
        if (nums[index] > high) return max(1 + recurse(nums, nums[index], index + 1), recurse(nums, high, index + 1));
        return recurse(nums, high, index + 1);
         
    }

    int lengthOfLIS(vector<int>& nums) {
        return recurse(nums, INT_MIN, 0);
    }
};
