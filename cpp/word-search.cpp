/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.

*/

/* O(m*n*l), O(m*n+l) */
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (word.size() <= 0) {
            return false;
        }
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {

                if (board[i][j] == word[0]) {
                    vector<vector<bool>> mask(board.size(), vector<bool>(board[0].size(), false));
                    if (exist_recur(board, i, j, word, 0, mask))
                        return true;
                }
            }
        }

        return false;
    }
private:
    bool exist_recur(vector<vector<char>>& board, int i, int j, string &word, int idx, vector<vector<bool>>& mask) {
        const static vector<pair<int, int>> dirs {{0,1}, {0,-1}, {1,0}, {-1,0}};
        if (idx >= word.size()) {
            return true;
        }

        if (board[i][j] != word[idx]) {
            return false;
        } else if (idx+1 == word.size()) {
            return true;
        }

        mask[i][j] = true;

        for (auto &p : dirs) {
            auto new_i = p.first + i;
            auto new_j = p.second + j;
            if (new_i>=0 && new_i<board.size() && new_j>=0 && new_j<board[0].size() && !mask[new_i][new_j]) {
                if (exist_recur(board, new_i, new_j, word, idx+1, mask)) {
                    return true;
                }
            }
        }

        mask[i][j] = false;
        return false;
    }
};
