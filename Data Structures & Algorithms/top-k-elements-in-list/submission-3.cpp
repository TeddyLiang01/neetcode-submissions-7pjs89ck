class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> intCount;
        for (int i : nums) {
            if (intCount.find(i) != intCount.end()) {
                ++intCount[i];
            } else {
                intCount[i] = 1;
            }
        }
        vector<vector<int>> countStore(nums.size() + 1);
        countStore.reserve(k + 1);
        for (auto i : intCount) {
            countStore[i.second].push_back(i.first);
        }

        vector<int> returnVector;
        returnVector.reserve(k);
        for (int i = countStore.size() - 1; i >= 0; --i) {
            if (returnVector.size() >= k) {
                break;
            } else if (countStore[i].size() != 0) {
                while (countStore[i].size() != 0 && returnVector.size() < k) {
                    returnVector.push_back(countStore[i].back());
                    countStore[i].pop_back();
                }
            }
        }

        return returnVector;
    }
};
