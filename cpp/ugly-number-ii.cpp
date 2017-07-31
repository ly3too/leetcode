/*
Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

Note that 1 is typically treated as an ugly number, and n does not exceed 1690.
*/

#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <iomanip>
#include <stack>
#include <ctime>
#include <ctype.h>
#include <sstream>
#include <map>
#include <cmath>
#include <unordered_map>
#include <queue>
#include <typeinfo>
#include "print_container.hpp"

using namespace std;

/* DP: if a number is an ugly number then it multply 2,3,5 is also a ugly number,
multply all previous ugly number and place in order to get the later ugly numbers */
/* O(n), O(n) */
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ugs(n);

        ugs[0] = 1;
        int f2 = 2, f3 = 3, f5 = 5; // next ugly number that has factor 2, 3, 5;
        int if2 =0, if3 = 0, if5 = 0;
        for (int i=1; i<n; ++i) {
            int next_val = min(min(f2, f3), f5);
            ugs[i] = next_val;
            if (next_val == f2) {
                f2 = 2*ugs[++if2];
            }
            if (next_val == f3) {
                f3 = 3*ugs[++if3];
            }
            if (next_val == f5) {
                f5 = 5*ugs[++if5];
            }
        }

        return ugs[n-1];
    }
};

/* solution2: use min heap to get the next ugly value, O(n), O(1) */
class Solution2 {
public:
    int nthUglyNumber(int n) {
        ugs.emplace(1);

        for (int i=1; i<n; ++i) {
            long long val = ugs.top();
            ugs.pop();
            if (val%2 == 0) { // multiple of 2
                ugs.emplace(2*val);

            } else if (val%3 == 0) { // multiple of 3 but not 2;
                ugs.emplace(2*val);
                ugs.emplace(3*val);

            } else { // multiple of 5 by not 2,3, or just 1;
                ugs.emplace(2*val);
                ugs.emplace(3*val);
                ugs.emplace(5*val);
            }
        }

        return ugs.top();
    }

    void print_queue() {
        while (!ugs.empty()) {
            cout << ugs.top() << " ";
            ugs.pop();
        }
    }

private:
    priority_queue<long long, vector<long long>, greater<long long>> ugs;
};

int main() {
    int x = 1481;
    Solution2 s2;
    cout << x << " : " << s2.nthUglyNumber(x) << endl;
    s2.print_queue();
    cout << endl;
}
