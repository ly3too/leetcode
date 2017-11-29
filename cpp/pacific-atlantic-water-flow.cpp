/*
Given an m x n matrix of non-negative integers representing the height of each unit cell in a continent, the "Pacific ocean" touches the left and top edges of the matrix and the "Atlantic ocean" touches the right and bottom edges.

Water can only flow in four directions (up, down, left, or right) from a cell to another one with height equal or lower.

Find the list of grid coordinates where water can flow to both the Pacific and Atlantic ocean.

Note:
The order of returned grid coordinates does not matter.
Both m and n are less than 150.
Example:

Given the following 5x5 matrix:

  Pacific ~   ~   ~   ~   ~
       ~  1   2   2   3  (5) *
       ~  3   2   3  (4) (4) *
       ~  2   4  (5)  3   1  *
       ~ (6) (7)  1   4   5  *
       ~ (5)  1   1   2   4  *
          *   *   *   *   * Atlantic

Return:

[[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] (positions with parentheses in above matrix).
*/
/* o(m*N) , o(M* N)*/
class Solution {
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        res.clear();
        if (matrix.empty() || matrix[0].empty())
            return res;

        m = matrix.size();
        n = matrix[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));
        for (int i=0; i<m; ++i) {
            expand(matrix, visited, PACIFIC, numeric_limits<int>::min(), i, 0);
            expand(matrix, visited, ATLANTIC, numeric_limits<int>::min(), i, n-1);
        }

        for (int j=0; j<n; ++j) {
            expand(matrix, visited, PACIFIC, numeric_limits<int>::min(), 0, j);
            expand(matrix, visited, ATLANTIC, numeric_limits<int>::min(), m-1, j);
        }

        return res;
    }
private:
    enum ocean{PACIFIC = 1, ATLANTIC = 2};
    int m;
    int n;
    vector<pair<int, int>> res;

    void expand(vector<vector<int>>& matrix, vector<vector<int>>& visited, int mask, int prev, int i, int j) {
        const static vector<pair<int, int>> DIRS {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        if (i < 0 || i >= m || j < 0 || j >= n || matrix[i][j] < prev || (visited[i][j] & mask) == mask) {
            return;
        }

        visited[i][j] |= mask;
        if ((visited[i][j] & PACIFIC) && (visited[i][j] & ATLANTIC))
            res.emplace_back(i, j);

        for (auto& dir : DIRS) {
            expand(matrix, visited, mask, matrix[i][j], i+dir.first, j+dir.second);
        }
    }
};
