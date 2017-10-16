/*
Given the height m and the length n of a m * n Multiplication Table,
and a positive integer k, you need to return the k-th smallest number in this table.
*/

class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        auto left = 1;
        auto right = m*n;

        while (left <= right) {
            auto mid = (left + right) / 2;
            if (count_smaller(mid, m, n) < k) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return left;
    }

private:
    int count_smaller(int target, int m, int n) {
        int cnt = 0;
        for (int i=1; i <= m; ++i) {
            cnt += min(n, target/m);
        }

        return cnt;
    }
};
