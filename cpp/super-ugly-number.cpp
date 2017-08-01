/*
Write a program to find the nth super ugly number.

Super ugly numbers are positive numbers whose all prime factors are in the given prime
list primes of size k. For example, [1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28, 32] is the
sequence of the first 12 super ugly numbers given primes = [2, 7, 13, 19] of size 4.

Note:
(1) 1 is a super ugly number for any given primes.
(2) The given numbers in primes are in ascending order.
(3) 0 < k ≤ 100, 0 < n ≤ 106, 0 < primes[i] < 1000.
(4) The nth super ugly number is guaranteed to fit in a 32-bit signed integer.
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

/* DP solution, O(n*k), O(n+k) */
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> ugs(n);
        vector<int> idx(primes.size(), 0);
        vector<int> next_val(primes);

        ugs[0] = 1;

        for (int i=1; i<n; ++i) {
            int val = *min_element(next_val.begin(), next_val.end());
            ugs[i] = val;
            for (int j=0; j<primes.size(); ++j) {
                if (val == next_val[j]) {
                    ++idx[j];
                    next_val[j] = ugs[idx[j]] * primes[j];
                }
            }
        }

        return ugs[n-1];
    }
};
