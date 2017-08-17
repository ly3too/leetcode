/*
Implement pow(x, n).
*/

/* O(logN) */
class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0)
            return 0;
        if (n == 0)
            return 1;
        if (n == 1)
            return x;

        if (n < 0 && n != -n) {
            return 1.0/myPow(x, -n);
        }

        double tmp = myPow(x, n/2);
        if (n % 2 == 0) {
            return tmp * tmp;

        } else {
            return x * tmp * tmp;

        }
    }
};
