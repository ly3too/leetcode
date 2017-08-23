/*
Given a positive integer n, break it into the sum of at least two positive integers and maximize the product of those integers. Return the maximum product you can get.
For example, given n = 2, return 1 (2 = 1 + 1); given n = 10, return 36 (10 = 3 + 3 + 4).
Note: You may assume that n is not less than 2 and not larger than 58.
*/

/* greedy, O(1)*/
class Solution {
public:
    int integerBreak(int n) {
        if (n <= 2)
            return 1;
        if (n == 3)
            return 2;

        int x = n/3;
        if (n % 3 == 1) {
            x = x-1;
            return static_cast<int>(pow(3, x)) * 4;
        } else if (n % 3 == 2) {
            return static_cast<int>(pow(3, x)) * 2;
        } else {
            return static_cast<int>(pow(3, x));
        }
    }
};
