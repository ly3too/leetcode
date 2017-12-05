/*
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.



Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement,
where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
*/

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        this -> n = n;
        col = vector<bool> (n, false);
        diag = vector<bool> (2*n, false);
        anti_diag = vector<bool> (2*n, false);
        tmp_res = vector<int> (n, 0);
        solveNQueens_recur(0);

        vector<vector<string>> result;
        for (auto &resi : res) {
            vector<string> str_res(n, string(n, '.'));
            for (int i = 0; i < n; ++i) {
                str_res[i][resi[i]] = 'Q';
            }
            result.emplace_back(move(str_res));
        }
        return result;
    }
private:
    vector<bool> col;
    vector<bool> diag;
    vector<bool> anti_diag;
    vector<vector<int>> res;
    vector<int> tmp_res;
    int n;

    void solveNQueens_recur(int row) {
        if (row >= n) {
            res.emplace_back(tmp_res);
            return;
        }

        for (int i=0; i<n; ++i) {
            if (col[i] || diag[row + i] || anti_diag[row + n - i]) {
                continue;
            } else {
                col[i] = diag[row + i] = anti_diag[row + n - i] = true;
                tmp_res[row] = i;
                solveNQueens_recur(row+1);
                col[i] = diag[row + i] = anti_diag[row + n - i] = false;
            }
        }
    }
};
