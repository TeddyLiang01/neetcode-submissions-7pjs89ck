class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxJump = nums[0];
        int cur = 0;
        while (maxJump >= cur && cur < nums.size()) {
            maxJump = max(cur + nums[cur], maxJump);
            cur++;
        }
        return maxJump >= nums.size() - 1;
    }
};
