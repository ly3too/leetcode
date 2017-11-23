/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

11110
11010
11000
00000
Answer: 1

Example 2:

11000
11000
00100
00011
Answer: 3
*/

/* O(n), O(n) */
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0)
            return 0;

        auto m = grid.size();
        auto n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        int cnt = 0;
        for (auto i=0; i<m; ++i) {
            for (auto j=0; j<n; ++j) {
                if (grid[i][j] != '0' && !visited[i][j]) {
                    ++cnt;
                    visit(grid, visited, i, j);
                }
            }
        }

        return cnt;
    }

private:
    void visit(vector<vector<char>>& grid, vector<vector<bool>> &visited, int i, int j) {
        auto m = grid.size();
        auto n = grid[0].size();

        if (grid[i][j]=='0' || visited[i][j])
            return;

        visited[i][j] = true;

        if (i != 0)
            visit(grid, visited, i-1, j);
        if (i+1 < m)
            visit(grid, visited, i+1, j);
        if (j != 0)
            visit(grid, visited, i, j-1);
        if (j+1 < n)
            visit(grid, visited, i, j+1);
    }
};
