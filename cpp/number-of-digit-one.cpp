/*
Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.

For example:
Given n = 13,
Return 6, because digit 1 occurred in the following numbers: 1, 10, 11, 12, 13.
*/

/* split numer into left right and cur part */
/* O(log(n)) */
class Solution {
public:
    int countDigitOne(int n) {
        constexpr int k = 1;
        if (n < 0)
            return 0;

        int left = n;
        int pow_n = 1;
        int cnt = 0;
        do {
            auto right = n % pow_n;
            auto cur = left % 10;

            /*000kxxx~LLLkxxx*/
            if (k < cur) {
                cnt += (left/10 + 1) * pow_n;

            /* 000k000 ~ LLLkRRR */
            } else if (k == cur) {
                cnt += (left/10) * pow_n + right + 1;

            /* k > cur, 000k000 ~ (LLL-1)K000 */
            } else {
                cnt += (left/10) * pow_n;
            }

            /* 001k000 ~ LLLk000 */
            if (k == 0 && pow_n>1) {
                cnt -= pow_n;
            }

            pow_n *= 10;
            left /= 10;
        } while (left > 0);

        return cnt;
    }
};
