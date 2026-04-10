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
    bool canAttendMeetings(vector<Interval>& intervals) {
        unordered_map<int, bool> schedule;
        for (auto interval : intervals) {
            for (int i = interval.start + 1; i <= interval.end; ++i) {
                if (schedule.find(i) != schedule.end()) {
                    return false;
                } else {
                    schedule[i] = true; 
                }
            }
        }
        return true;
    }
};
