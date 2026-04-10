/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if (intervals.size() == 0) return 0;
        sort(intervals.begin(), intervals.end(), [](auto a, auto b) {
            return a.start < b.start;
        });
        return findMinDays(intervals);
    }

    int findMinDays(vector<Interval>& intervals) {
        if (intervals.size() == 0) return 0;
        Interval cur = intervals[0];
        intervals.erase(intervals.begin());
        
        for (auto it = intervals.begin(); it != intervals.end();) {
            if (it->start >= cur.end) {
                cur = *it;
                it = intervals.erase(it);
            } else {
                it++;
            }
        }
        return 1 + findMinDays(intervals);
    }
};
