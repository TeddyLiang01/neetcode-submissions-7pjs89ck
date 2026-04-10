class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        auto comp = [](const vector<int>& p1, const vector<int>& p2) {
            return p1[0] * p1[0] + p1[1] * p1[1] > p2[0] * p2[0] + p2[1] * p2[1];
        };

        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> minheap(comp);

        for (auto &p : points) {
            minheap.push({p[0], p[1]});
        }

        vector<vector<int>> ret;
        for (int i = 0; i < k; ++i) {
            ret.push_back(minheap.top());
            minheap.pop();
        }
        return ret;
    }
};
