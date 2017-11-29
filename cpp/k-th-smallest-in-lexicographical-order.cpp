/*
Given integers n and k, find the lexicographically k-th smallest integer in the range from 1 to n.

Note: 1 ≤ k ≤ n ≤ 109.

Example:

Input:
n: 13   k: 2

Output:
10

Explanation:
The lexicographical order is [1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9], so the second smallest number is 10.
*/

/*
General ideas:
1. Calculate the number of numbers that prefix with result.
Numbers prefixed by result are the union of the following intervals:
[result, result+1)
[result*10, (result+1)*10 )
[result*100, (result+1)*100 )
...
But they also shall belong to [1, n]
Therefore, we can easily calculate the number of elements prefixed by result using the following code (not considering overflow):

            int count = 0;
            for (int first = result, last = result + 1; // the first interval contains only one element: {result}
                first <= n; // the interval is not empty
                first *= 10, last *= 10) // increase a digit
            {
                // valid interval = [first, last) union [first, n]
                count += (min(n + 1, last) - first); // add the length of interval
            }
            */

/* O(log(n)^2), O(1), search for each digit requires log(n) and there are log(n) digits*/
class Solution {
public:
    int findKthNumber(int n, int k) {
        int res = 1;
        --k;
        while (k > 0) {
            /* calculate number of numbers prefix with res. {res, res*, res** ...} */
            auto cnt = 0;
            for (long long start = res, end = res + 1; start <= n; start *= 10, end *= 10) {
                cnt += min(end, n + 1LL) - start;
            }

            if (k >= cnt) { // skip res, res*, res**, res***
                k -= cnt;
                ++res;

            } else {
                res *= 10;
                --k;
            }
        }

        return res;
    }
};
