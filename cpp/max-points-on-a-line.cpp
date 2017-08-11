/*
Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
*/

#include "header.hpp"

#define DEBUG

#ifdef DEBUG
#define D(x) {x;}
#else
#define D(x) {;}
#endif

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

/* O(n^2), O(n) */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        int max_cnt = 0;
        for (int i=0; i<points.size(); ++i) {
            unordered_map<pair<int, int>, int, pair_hash> rate_cnt;
            int same = 0;
            int cur_max = 1;

            for (int j=i+1; j<points.size(); ++j) {
                auto dx = points[i].x - points[j].x;
                auto dy = points[i].y - points[j].y;

                if (dx==0 && dy==0) {
                    ++same;

                } else {
                    int divi = gcd(dx, dy);
                    pair<int, int> rate = make_pair(dx/divi, dy/divi);

                    if (rate_cnt.find(rate) != rate_cnt.end()) {
                        ++rate_cnt[rate];
                    } else {
                        rate_cnt[rate] = 2;
                    }

                    cur_max = max(cur_max, rate_cnt[rate]);
                }

            }

            max_cnt = max(max_cnt, cur_max+same);
        }

        return max_cnt;
    }

private:
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    struct pair_hash {
        template<class T, class U>
        size_t operator() (const pair<T,U>& x) const {
            return (hash<T>()(x.first) << 10) ^ hash<U>()(x.second);
        }
    };
};

/* O(n^2), O(n) */
class Solution2 {
public:
    int maxPoints(vector<Point>& points) {
        int max_cnt = 0;
        for (int i=0; i<points.size(); ++i) {
            unordered_map<long double, int> rate_cnt;
            int same = 0;
            int cur_max = 1;

            for (int j=i+1; j<points.size(); ++j) {
                auto dx = points[i].x - points[j].x;
                auto dy = points[i].y - points[j].y;

                if (dx==0 && dy==0) {
                    ++same;

                } else {
                    long double rate;
                    if (dx == 0) {
                        rate = numeric_limits<long double>::max();
                    } else {
                        rate = static_cast<long double>(dy) / dx;
                    }

                    if (rate_cnt.find(rate) != rate_cnt.end()) {
                        ++rate_cnt[rate];
                    } else {
                        rate_cnt[rate] = 2;
                    }

                    cur_max = max(cur_max, rate_cnt[rate]);
                }

            }

            max_cnt = max(max_cnt, cur_max+same);
        }

        return max_cnt;
    }
};

int main() {
    vector<Point> points {Point(0,0), Point(numeric_limits<int>::max()-2, numeric_limits<int>::max()-1), Point(numeric_limits<int>::max()-3, numeric_limits<int>::max()-2)};
    // vector<Point> points {Point(0,0), Point(1, 1), Point(-2, -2)};
    D( cout << Solution{}.maxPoints(points) << endl );
}
