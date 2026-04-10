class Solution {
public:
    int search(vector<int>& nums, int target) {
        // find the midpoint and repeat until target is found

        int highIndex = nums.size() - 1;
        int lowIndex = 0;
        int midIndex = 0;

        while (lowIndex <= highIndex) {
            midIndex = (highIndex + lowIndex) / 2;

            if (nums[midIndex] > target) {
                highIndex = midIndex - 1;
            } else if (nums[midIndex] < target) {
                lowIndex = midIndex + 1;
            } else {
                return midIndex;
            }
        }
        return -1;
    }
};
