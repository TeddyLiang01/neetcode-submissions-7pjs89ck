class Solution {
public:
    void search(vector<int>& nums, vector<int> curSet, int index, vector<vector<int>>& res) {
        if (index == nums.size()) {
            res.push_back(curSet);
            return;
        }
        curSet.push_back(nums[index]);
        search(nums, curSet, index + 1, res);
        curSet.pop_back();
        search(nums, curSet, index + 1, res);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curSet;
        search(nums, curSet, 0, res);
        return res;
    }
};
