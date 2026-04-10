class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int numsCount = nums.size();
        int fast = 0;
        int slow = 0;

        if (numsCount == 2) {
            return nums[0];
        }

        while (true) {
            if (fast == numsCount - 1) {
                fast = 1;
            } else if (fast == numsCount - 2) {
                fast = 0;
            } else {
                fast += 2;
            }
            
            if (slow == numsCount - 1) {
                slow = 0;
            } else {
                slow += 1;
            }
            
            if (nums[fast] == nums[slow]) {
                return nums[fast];
            }
        }
    }
};

