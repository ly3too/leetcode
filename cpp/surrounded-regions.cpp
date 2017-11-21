/*
Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

For example,
X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
*/

/* start with border, mark O and it's neighbor to B, then mark all rest 'O' to 'X' and 'B' to 'O'*/
/* O(m*n), O(m+n) */
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty())
            return;

        queue<pair<int, int>> que;

        for (int i=0; i<board.size(); ++i) {
            que.emplace(make_pair(i, 0));
            que.emplace(make_pair(i, board[0].size() - 1));
        }

        for (int i=0; i<board[0].size(); ++i) {
            que.emplace(make_pair(0, i));
            que.emplace(make_pair(board.size()-1, i));
        }

        while(!que.empty()) {
            int i;
            int j;

            tie(i, j) = que.front();
            que.pop();

            if(board[i][j] == 'O') {
                board[i][j] = 'B';

                if (i+1 < board.size() && board[i+1][j] == 'O') {
                    que.emplace(i+1, j);
                }
                if (i-1 > 0 && board[i-1][j] == 'O') {
                    que.emplace(i-1, j);
                }

                if (j+1 < board[0].size() && board[i][j+1] == 'O') {
                    que.emplace(i, j+1);
                }
                if (j-1 > 0 && board[i][j-1] == 'O') {
                    que.emplace(i, j-1);
                }
            }
        }

        for (int i=0; i<board.size(); ++i) {
            for (int j=0; j<board[0].size(); ++j) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if(board[i][j] == 'B') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};
