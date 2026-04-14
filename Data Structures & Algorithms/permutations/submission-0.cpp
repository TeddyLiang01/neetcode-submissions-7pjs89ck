class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        result.push_back({nums[0]});
        for (int i = 1; i < nums.size(); ++i) { // each number
            vector<vector<int>> newResult;
            for (int resIndex = 0; resIndex < result.size(); ++resIndex) { // each element in result
                for (int pos = 0; pos <= result[0].size(); ++pos) { // each position in each element
                    vector<int> newResElement = result[resIndex];
                    newResElement.insert(newResElement.begin() + pos, nums[i]);
                    newResult.push_back(newResElement);
                }
            }
            result = newResult;
        }
        return result;
    }
};

// {1}
// 1

// {1, 2}
// 12, 21

// {1, 2, 3}
// 312, 132, 123, 321, 231, 213