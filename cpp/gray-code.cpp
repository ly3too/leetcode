/*
The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2
*/

#include "header.hpp"

/* for every group, the highest bit is 1, i.e. 1<<i */
/* O(2^n) */
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res{0};

        for (int i=0; i<n; ++i) {
          for (int j = res.size()-1; j>=0; --j) {
            res.emplace_back(res[j] | (1<<i));
          }
        }

        return res;
    }
};

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;

        for (int i=0; i < (1<<n); ++i) {
          res.emplace_back((i>>1) ^ i);
        }

        return res;
    }
};
