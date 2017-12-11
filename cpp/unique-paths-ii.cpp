/*
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.
*/

/*  */

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        auto m = obstacleGrid.size();
        if (!m)
            return 0;
        auto n = obstacleGrid[0].size();

        vector<int> dp(n, 0);
        dp[0] = 1;

        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (obstacleGrid[i][j]) {
                    dp[j] = 0;
                } else if (j>0) {
                    dp[j] += dp[j-1];
                }
            }
        }

        return dp[n-1];
    }
};
