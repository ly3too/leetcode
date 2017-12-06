/*
Follow up for N-Queens problem.

Now, instead outputting board configurations, return the total number of distinct solutions.
*/

/* O(n!), O(n) */
class Solution {
public:
    int totalNQueens(int n) {
        this -> n = n;
        col = vector<bool> (n, false);
        diag = vector<bool> (2*n, false);
        anti_diag = vector<bool> (2*n, false);
        res_cnt = 0;
        solveNQueens_recur(0);

        return res_cnt;

    }
private:
    vector<bool> col;
    vector<bool> diag;
    vector<bool> anti_diag;
    int res_cnt;
    int n;

    void solveNQueens_recur(int row) {
        if (row >= n) {
            ++ res_cnt;
            return;
        }

        for (int i=0; i<n; ++i) {
            if (col[i] || diag[row + i] || anti_diag[row + n - i]) {
                continue;
            } else {
                col[i] = diag[row + i] = anti_diag[row + n - i] = true;
                solveNQueens_recur(row+1);
                col[i] = diag[row + i] = anti_diag[row + n - i] = false;
            }
        }
    }
};
