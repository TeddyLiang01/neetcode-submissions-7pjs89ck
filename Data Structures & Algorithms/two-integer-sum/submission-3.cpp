class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // make a hashmap and input all numbers with respective index
        unordered_map<int, int> numsIndex;
        for (int i = 0; i < nums.size(); ++i) {
            numsIndex[nums[i]] = i;
        }

        // loop through nums vector and try to find number to add to target
        for (int i = 0; i < nums.size(); ++i) {
            if (numsIndex.find(target - nums[i]) != numsIndex.end()) {
                if (i != numsIndex[target - nums[i]]) {
                    return {i, numsIndex[target - nums[i]]};
                }
            }
        }

    }
};
