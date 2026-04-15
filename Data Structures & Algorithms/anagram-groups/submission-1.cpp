class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> dict;

        for (int i = 0; i < strs.size(); ++i) {
            vector<int> count(26, 0);
            for (auto& c : strs[i]) {
                count[c - 'a']++;
            }
            string key = "";
            for (auto& num : count) {
                key += to_string(num);
                key += "-";
            }
            if (dict.count(key) == 0) dict[key] = {};
            dict[key].push_back(strs[i]);
        }

        vector<vector<string>> res;
        for (auto& p : dict) {
            res.push_back(p.second);
        }
        return res;
    }
};
