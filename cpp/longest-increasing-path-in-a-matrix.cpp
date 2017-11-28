/*
Given an integer matrix, find the length of the longest increasing path.

From each cell, you can either move to four directions: left, right, up or down. You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).

Example 1:

nums = [
  [9,9,4],
  [6,6,8],
  [2,1,1]
]
Return 4
The longest increasing path is [1, 2, 6, 9].

Example 2:

nums = [
  [3,4,5],
  [3,2,6],
  [2,2,1]
]
Return 4
The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
*/

/* O(m*n), O(m*n) */
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        auto m = matrix.size();
        if (m == 0)
            return 0;
        auto n = matrix[0].size();
        if (n == 0)
            return 0;

        int res = 0;
        vector<vector<int>> max_lenth(m, vector<int>(n, 0));
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                res = max(res, longestIncreasingPath_dfs(matrix, i, j, max_lenth));
            }
        }

        return res;
    }
private:
    int longestIncreasingPath_dfs(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& max_lenth){
        if (max_lenth[i][j])
            return max_lenth[i][j];
        const static vector<pair<int, int>> dirs{{-1,0}, {1, 0}, {0, 1}, {0, -1}};
        auto res = 1;
        for (auto &dir : dirs) {
            auto x = dir.first + i;
            auto y = dir.second + j;
            if (x >= 0 && x < matrix.size() && y >= 0 && y < matrix[0].size() && matrix[i][j] < matrix[x][y]) {
                res = max(res, 1+longestIncreasingPath_dfs(matrix, x, y, max_lenth));
            }
        }

        max_lenth[i][j] = res;
        return res;
    }
};
