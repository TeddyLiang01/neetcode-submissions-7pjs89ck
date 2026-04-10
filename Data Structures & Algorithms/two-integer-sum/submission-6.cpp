class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> tarMap; // value : index
        for (int i = 0; i < nums.size(); ++i) {
            if (tarMap.count(target - nums[i]) != 0) {
                return {tarMap[target - nums[i]], i};
            }
            tarMap[nums[i]] = i;
        }
    }
};
