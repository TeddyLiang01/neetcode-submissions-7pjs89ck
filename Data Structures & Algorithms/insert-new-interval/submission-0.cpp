class Solution {
public:
    bool contains(vector<int> &interval, int n) {
        if (interval[0] <= n && interval[1] >= n) return true;
        return false;
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;

        for (int i = 0; i < intervals.size(); ++i) {
            if (intervals[i][0] > newInterval[1]) { // before interval
                res.push_back(newInterval);
                for (int j = i; j < intervals.size(); ++j) {
                    res.push_back(intervals[j]);
                }
                return res;
            } else if (intervals[i][1] < newInterval[0]) { // after interval
                res.push_back(intervals[i]);
            } else { // intervals[i][0] <= newInterval[1] and intervals[i][1] >= newInterval[0]
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
        }
        res.push_back(newInterval);
        return res;
    }
};
