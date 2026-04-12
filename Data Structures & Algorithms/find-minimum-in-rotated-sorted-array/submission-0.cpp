class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0;
        int r = nums.size() - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[l] <= nums[mid] && nums[mid] <= nums[r]) {
                r = mid - 1;
            } else if (nums[l] >= nums[mid] && nums[mid] <= nums[r]) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return nums[l];
    }
};

// [1, 2, 3]
// small, mid, large -> large = midIndex
// [3, 1, 2]
// large, small, mid -> large = midIndex
// [2, 3, 1]
// mid, large, small -> small = midIndex



