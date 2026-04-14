class Solution {
public:
    void recurse(vector<int>& nums, vector<vector<int>>& result, vector<int>& current, int index) {
        if (index == nums.size()) {
            result.push_back(current);
            return;
        }

        current.push_back(nums[index]);
        recurse(nums, result, current, index + 1);
        current.pop_back();

        index++;
        while (nums[index - 1] == nums[index]) {
            index++;
        }
        recurse(nums, result, current, index);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> current;
        recurse(nums, result, current, 0);
        return result;
        
    }
};

// 4, 4, 4
