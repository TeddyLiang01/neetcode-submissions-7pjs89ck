class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maximum = nums[0];
        int left = 0;
        int curSum = 0;

        for (int i = 0; i < nums.size(); ++i) {
            if (curSum <= 0) {
                curSum = nums[i];
                left = i;
            } else {
                curSum += nums[i];
            }
            maximum = max(curSum, maximum);
        }

        return maximum;

    }
};
