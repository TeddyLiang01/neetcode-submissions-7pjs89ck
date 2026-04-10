class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        if (nums.size() == 0) {
            return {};
        }

        vector<vector<int>> ret;
        dfs(nums, 0, {}, ret);
        return ret;
    }

    void dfs(vector<int>& nums, int curElem, vector<int> curSubset, vector<vector<int>>& ret) {
        if (curElem == nums.size()) {
            ret.push_back(curSubset);
        } else {
            dfs(nums, curElem + 1, curSubset, ret);
            curSubset.push_back(nums[curElem]);
            dfs(nums, curElem + 1, curSubset, ret);
        }
        
    }
};


// 1 2 3
// size - 1: 2
// 0 {}

// 1 {}

// 