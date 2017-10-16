/*
Given a set of intervals, for each of the interval i, check if there exists an interval
j whose start point is bigger than or equal to the end point of the interval i, which can
 be called that j is on the "right" of i.

For any interval i, you need to store the minimum interval
 j's index, which means that the interval j has the minimum start point to build the
 "right" relationship for interval i. If the interval j doesn't exist, store -1 for the interval i.
 Finally, you need output the stored value of each interval as an array.
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

/* O(nlog(n)), O(n) */
class Solution {
public:
    vector<int> findRightInterval(vector<Interval>& intervals) {
        map<int, int> lookup;
        for (int i=0; i<intervals.size(); ++i) {
            lookup[intervals[i].start] = i;
        }

        vector<int> res;
        for (auto &intv : intervals) {
            auto it = lookup.lower_bound(intv.end);
            if (it != lookup.end()) {
                res.emplace_back(it -> second);
            } else {
                res.emplace_back(-1);
            }
        }

        return res;
    }
};
