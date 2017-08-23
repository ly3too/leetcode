/*
Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number
of 1's in their binary representation and return them as an array.
Example:
For num = 5 you should return [0,1,1,2,1,2].
*/

/* DP, O(n), O(n) */
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num+1);
        res[0] = 0;

        for (int i=1; i<=num; ++i) {
            res[i] = (i & 1) + res[i>>1];
        }

        return res;
    }
};
