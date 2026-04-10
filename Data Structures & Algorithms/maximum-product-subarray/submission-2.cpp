class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int curMax = nums[0];
        int curMin = nums[0];
        int res = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                curMax = 1;
                curMin = 1;
                res = max(res, 0);
                continue;
            }

            int tempCurMax = curMax;
            curMax = max({curMax * nums[i], curMin * nums[i], nums[i]});
            curMin = min({tempCurMax * nums[i], curMin * nums[i], nums[i]});
            res = max(curMax, res);
        }
        return res;
    }
};
