/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?
*/

/* P[i][j] = P[i-1][j] + P[i][j-1] */

/* O(m*n), O(min(m, n)) */
class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m < n)
            return uniquePaths(n, m);
        vector<int> dp(n, 1);

        for (int i=1; i<m; ++i) {
            for (int j=1; j<n; ++j) {
                dp[j] += dp[j-1];
            }
        }

        return dp[n-1];
    }
};
