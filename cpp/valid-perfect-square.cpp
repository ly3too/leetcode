/*
Given a positive integer num, write a function which returns True if num is a perfect square else False.

Note: Do not use any built-in library function such as sqrt.

Example 1:

Input: 16
Returns: True
*/

/* O(log(n)) */
class Solution {
public:
    bool isPerfectSquare(int num) {
        auto left = 1;
        auto right = num;

        while (left <= right) {
            long long mid = (left + right) / 2;

            if (mid * mid == num) {
                return true;
            } else if (mid * mid > num) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return left * left == num;
    }
};
