/*
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
You may assume that the intervals were initially sorted according to their start times.
Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].
*/

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res;
        if (intervals.size() == 0) {
            res.emplace_back(newInterval);
            return res;
        }

        int i = 1;
        while (i<intervals.size() && intervals[i].start<newInterval.start) {
            res.emplace_back(intervals[i-1]);
            ++i;
        }
        --i;

        auto last = intervals[i];
        if (last.start > newInterval.end) {
            res.emplace_back(newInterval);

        } else if (last.start > newInterval.start) {
            last.start = newInterval.start;
            last.end = max(newInterval.end, last.end);

        } else if (last.end < newInterval.start) {
            res.emplace_back(move(last));
            last = newInterval;

        } else {
            last.end = max(last.end, newInterval.end);
        }
        for (++i; i<intervals.size(); ++i) {
            if (last.end < intervals[i].start) {
                res.emplace_back(move(last));
                last = intervals[i];
            } else {
                last.end = max(last.end, intervals[i].end);
            }
        }
        res.emplace_back(last);

        return res;
    }
};
