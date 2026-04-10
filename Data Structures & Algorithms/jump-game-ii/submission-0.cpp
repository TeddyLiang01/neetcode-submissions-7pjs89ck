class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size() + 1, INT_MAX);

        dp[0] = 0;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j <= i + nums[i]; ++j) {
                if (j >= nums.size()) break;
                dp[j] = min(dp[j], dp[i] + 1);
            }
        }

        return dp[nums.size() - 1];
    }
};

/*
input 2 4 1 1 1 1
dp:   0 1 

*/
