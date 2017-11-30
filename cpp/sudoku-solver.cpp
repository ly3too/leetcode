/*
Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution.
*/

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board, 0, 0);
    }

private:
    bool check(vector<vector<char>>& board, int x, int y) {
        for (int i=0; i < 9; ++i) {
            if (i != x && board[i][y] == board[x][y])
                return false;
        }

        for (int j=0; j < 9; ++j) {
            if ( j != y && board[x][j] == board[x][y])
                return false;
        }

        for (int i = (x/3)*3; i < (x/3)*3+3; ++i) {
            for (int j = (y/3)*3; j < (y/3)*3+3; ++j) {
                if ((i != x || j != y) && board[i][j] == board[x][y]) {
                    return false;
                }
            }
        }

        return true;
    }

    bool solve(vector<vector<char>>& board, int x, int y) {
        auto new_x = x;
        auto new_y = y+1;
        if (x >= 9)
            return true;
        if (new_y >= 9) {
            ++new_x;
            new_y = 0;
        }

        // cout << x << " " << y << " " << board[x][y] << endl;

        if (board[x][y] == '.') {
            for (int i=0; i<9; ++i) {
                board[x][y] = '1' + i;
                if (check(board, x, y) && solve(board, new_x, new_y))
                    return true;
            }

            // backtracking, restore board[x][y]
            board[x][y] = '.';
            return false;

        } else {
            return solve(board, new_x, new_y);
        }

    }
};
