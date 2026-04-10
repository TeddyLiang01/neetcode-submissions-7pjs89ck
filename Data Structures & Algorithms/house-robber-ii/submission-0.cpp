class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        
        vector<int> maxWithFirst(nums.size(), 0);
        vector<int> maxWithLast(nums.size(), 0);
        maxWithLast[0] = 0;
        maxWithLast[1] = nums[1];
        maxWithFirst[0] = 0;
        maxWithFirst[1] = nums[0];
        for (int i = 2; i < nums.size(); ++i) {
            maxWithFirst[i-2] + nums[i-1] > maxWithFirst[i-1] ? maxWithFirst[i] = maxWithFirst[i-2] + nums[i-1] : maxWithFirst[i] = maxWithFirst[i-1];
            maxWithLast[i-2] + nums[i] > maxWithLast[i-1] ? maxWithLast[i] = maxWithLast[i-2] + nums[i] : maxWithLast[i] = maxWithLast[i-1];
        }
        return max(maxWithFirst[nums.size() - 1], maxWithLast[nums.size() - 1]);
    }
};
