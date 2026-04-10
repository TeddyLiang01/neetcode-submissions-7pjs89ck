class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        } else if (nums.size() == 1) {
            return nums[0];
        } else if (nums.size() == 2) {
            return max(nums[0], nums[1]);
        }

        int rob1 = 0;
        int rob2 = 0;

        for (int i = 0; i < nums.size(); ++i) {
            int temp = max(rob1 + nums[i], rob2);
            rob1 = rob2;
            rob2 = temp;
        }
        return rob2;
    }
};

// 1 1 3 3
// 


// 2 9 8 3 6

// rob1: 2
// rob2: 9

// 2 8 6
