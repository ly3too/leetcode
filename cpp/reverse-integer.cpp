/*
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

click to show spoilers.

Note:
The input is assumed to be a 32-bit signed integer. Your function should return 0 when the reversed integer overflows.
*/
#include "header.hpp"

class Solution {
public:
    int reverse(int x) {
        bool sign = (x < 0);
        if (sign)
            x = -x;

        int y = 0;
        int ys;

        while (x != 0) {
            ys = y;
            y = y*10 + x%10;
            x /= 10;
            if (y/10 != ys) {
                return 0;
            }
        }

        return sign ? -y : y;
    }
};
