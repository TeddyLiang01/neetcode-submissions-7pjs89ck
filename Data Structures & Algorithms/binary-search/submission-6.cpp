class Solution {
public:
    int search(vector<int>& nums, int target) {
        // find the midpoint and repeat until target is found

        int highIndex = nums.size() - 1;
        int lowIndex = 0;
        int midIndex = 0;
        int prevIndex = 0;

        while (nums[midIndex] != target) {
            midIndex = ((highIndex + lowIndex) / 2) + 1;
            if (nums[midIndex] == target) break;
            midIndex -= 1;

            if (prevIndex == midIndex) break;
            prevIndex = midIndex;

            if (nums[midIndex] > target) {
                highIndex = midIndex;
            } else if (nums[midIndex] < target) {
                lowIndex = midIndex;
            }
        }
        if (nums[midIndex] == target) {
            return midIndex;
        }
        return -1;
    }
};
