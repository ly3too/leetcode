/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example 1:
[[1,3,1],
 [1,5,1],
 [4,2,1]]
Given the above grid map, return 7. Because the path 1→3→1→1→1 minimizes the sum.

*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        auto m = grid.size();
        if (!m)
            return 0;
        auto n = grid[0].size();
        for (int j=1; j<n; ++j) {
            grid[0][j] += grid[0][j-1];
        }

        for (int i=1; i<m; ++i) {
            grid[i][0] += grid[i-1][0];
            for (int j=1; j<n; ++j) {
                grid[i][j] += min(grid[i][j-1], grid[i-1][j]);
            }
        }

        return grid[m-1][n-1];
    }
};
