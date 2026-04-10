class Solution {
public:
    int search(vector<int>& nums, int target) {
        int leftI = 0;
        int rightI = nums.size() - 1;

        while(leftI <= rightI) {
            int midI = (leftI + rightI) / 2;
            if (target > nums[midI]) {
                leftI = midI + 1;
            } else if (target < nums[midI]) {
                rightI = midI - 1;
            } else {
                return midI;
            }
        }
        return -1;
    }
};
