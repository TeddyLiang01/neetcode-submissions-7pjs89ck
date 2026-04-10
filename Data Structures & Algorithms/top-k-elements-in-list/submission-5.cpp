class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (auto& n : nums) {
            count[n]++;
        }

        vector<vector<int>> freq(nums.size() + 1, vector<int>());
        for (auto& pair : count) {
            freq[pair.second].push_back(pair.first);
        }

        vector<int> res;

        for (int i = freq.size() - 1; i >= 0; --i) {
            for (int j = 0; j < freq[i].size(); ++j) {
                res.push_back(freq[i][j]);
                k--;
            }
            if (k <= 0) return res;
        }
        return {};
    }
};
