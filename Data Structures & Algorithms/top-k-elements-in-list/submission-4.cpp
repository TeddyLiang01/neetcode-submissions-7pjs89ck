class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (auto& n : nums) {
            count[n]++;
        }

        vector<pair<int, int>> pairs;
        for (auto& pair : count) {
            pairs.push_back(make_pair(pair.second, pair.first));
        }

        priority_queue<pair<int, int>> pq(pairs.begin(), pairs.end());

        vector<int> ret;
        for (int i = 0; i < k; ++i) {
            ret.push_back(pq.top().second);
            pq.pop();
        }
        return ret;
    }
};
