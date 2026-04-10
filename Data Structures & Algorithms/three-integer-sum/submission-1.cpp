class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int prev = INT_MIN;
        vector<vector<int>> res;

        for (int i = 0; i < nums.size() - 2; ++i) {
            if (nums[i] == prev) continue;

            int l = i + 1;
            int r = nums.size() - 1;

            int target = -nums[i];
            while (l < r) {
                if (nums[l] + nums[r] == target) {
                    res.push_back({nums[l], nums[r], nums[i]});
                    l++;
                    r--;
                    while (l < r && nums[l] == nums[l - 1]) ++l;
                } else if (nums[l] + nums[r] > target) r--;
                else l++;
            }

            prev = nums[i];
        }
        return res;
    }
};
