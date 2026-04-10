class Solution {
public:
    void search(vector<int>& nums, vector<int> curSet, int index, vector<vector<int>>& res) {
        if (index == nums.size()) return;
        curSet.push_back(nums[index]);
        search(nums, curSet, index + 1, res);
        res.push_back(curSet);
        curSet.pop_back();
        search(nums, curSet, index + 1, res);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curSet;
        res.push_back(curSet);
        search(nums, curSet, 0, res);
        return res;
    }
};
