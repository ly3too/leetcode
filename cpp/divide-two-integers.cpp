/*
Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT.
*/
#include "header.hpp"

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == numeric_limits<int>::min() && divisor == -1 || divisor==0 && dividend != 0) {
            return numeric_limits<int>::max();
        }
        if (dividend == 0)
            return 0;

        auto a = dividend > 0 ? -dividend : dividend;
        auto b = divisor > 0 ? -divisor : divisor;

        int shift;
        for (shift = 0; shift<32 && (b<<shift) < 0; ++shift) {
            ;
        }
        --shift;

        int res = 0;
        for (; shift>=0; --shift) {
            if (a <= (b<<shift)) {
                a -= (b<<shift);
                res += 1<<shift;
            }
        }

        return ((dividend^divisor) < 0) ? -res : res;
    }
};
