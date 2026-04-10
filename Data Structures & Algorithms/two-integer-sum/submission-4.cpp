class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // make a hashmap and input all numbers with respective index
        unordered_map<int, int> numsIndex;
        for (int i = 0; i < nums.size(); ++i) {
            if (numsIndex.find(target - nums[i]) != numsIndex.end()) {
                if (i != numsIndex[target - nums[i]]) {
                    return {numsIndex[target - nums[i]], i};
                }
            }
            numsIndex[nums[i]] = i;
        }

    }
};
