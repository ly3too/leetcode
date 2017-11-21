/*
Given a data stream input of non-negative integers a1, a2, ..., an, ..., summarize the numbers seen so far as a list of disjoint intervals_.

For example, suppose the integers from the data stream are 1, 3, 7, 2, 6, ..., then the summary will be:

[1, 1]
[1, 1], [3, 3]
[1, 1], [3, 3], [7, 7]
[1, 3], [7, 7]
[1, 3], [6, 7]
*/
#include "header.hpp"

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

ostream& operator <<(ostream& os, const Interval &intv) {
    os << "[" << intv.start << ", " << intv.end << "]";
    return os;
}

constexpr static auto cmp2 = [] (const Interval &i1, const Interval &i2) -> bool {return i1.start == i2.start ? i1.end < i2.end : i1.start < i2.start;};
class SummaryRanges {
public:
    /** Initialize your data structure here. */
    SummaryRanges() : intervals_(cmp) {

    }

    void addNum(int val) {
        auto start = val;
        auto end = val;
        auto it = intervals_.lower_bound(Interval(val, val));

        if (it != intervals_.end() && it -> start <= start + 1 && it -> end >= end) {
            end = it -> end;
            it = intervals_.erase(it);
        }

        if (it != intervals_.begin()) {
            --it;

            if (it != intervals_.end() && it -> end + 1 >= start) {
                start = min(start, it -> start);
                end = max(end, it -> end);
                intervals_.erase(it);
            }
        }

        intervals_.insert(Interval(start, end));
    }

    vector<Interval> getIntervals() {
        return {intervals_.begin(), intervals_.end()};
    }

private:
    const static function<bool(const Interval &i1, const Interval &i2)> cmp;
    /*struct Cmp {
        bool operator()(const Interval &i1, const Interval &i2) {
            return i1.start == i2.start ? i1.end < i2.end : i1.start < i2.start;
        }
    };*/
    set<Interval, decltype(cmp)> intervals_;

};
const function<bool(const Interval &i1, const Interval &i2)> SummaryRanges::cmp = [] (const Interval &i1, const Interval &i2) -> bool {return i1.start == i2.start ? i1.end < i2.end : i1.start < i2.start;};

int main() {
    auto pso = new SummaryRanges();
    auto &so = *pso;
    so.addNum(0);
    cout << so.getIntervals() << endl;
    so.addNum(0);
    cout << so.getIntervals() << endl;
    so.addNum(1);
    cout << so.getIntervals() << endl;
    so.addNum(4);
    cout << so.getIntervals() << endl;
    so.addNum(8);
    cout << so.getIntervals() << endl;
    so.addNum(7);
    cout << so.getIntervals() << endl;
    so.addNum(5);
    cout << so.getIntervals() << endl;

    return 0;
}
