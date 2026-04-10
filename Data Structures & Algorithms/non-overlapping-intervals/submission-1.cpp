class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
            return a[1] < b[1];
        });

        int lastEnd = INT_MIN;
        int numSkip = 0;
        for (auto& interval : intervals) {
            if (interval[0] < lastEnd) numSkip++;
            else lastEnd = interval[1];
        }
        return numSkip;
    }
};
