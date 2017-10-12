/*
Implement int sqrt(int x).

Compute and return the square root of x.
*/


class Solution {
public:
    int mySqrt(int x) {
        if (x < 2)
            return x;
        auto left = 1;
        auto right = x / 2;
        while (left <= right) {
            long long mid = (left + right) / 2;
            if (x == mid * mid)
                return mid;
            else if (mid*mid > x)
                right = mid - 1;
            else
                left = mid + 1;
        }

        return left - 1;
    }
};
