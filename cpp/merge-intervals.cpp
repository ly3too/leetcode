/*
Given a collection of intervals, merge all overlapping intervals.
For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */


class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        auto less = [](const Interval &v1, const Interval &v2) {return v1.start < v2.start;};
        sort(intervals.begin(), intervals.end(), less);

        vector<Interval> res;
        if (intervals.size() == 0) {
            return res;
        }
        auto last = intervals[0];
        for (auto &cur : intervals) {
            if (last.end < cur.start) {
                res.emplace_back(move(last));
                last = cur;
            } else {
                last.end = max(cur.end, last.end);
            }
        }
        res.emplace_back(move(last));

        return res;
    }
};
