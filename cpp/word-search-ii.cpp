/*
Given a 2D board and a list of words from the dictionary, find all words in the board.

Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

For example,
Given words = ["oath","pea","eat","rain"] and board =

[
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]
Return ["eat","oath"].
*/

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        unordered_set<string> res;
        for (auto &word : words) {
            if (exist(board, word)) {
                res.insert(word);
            }
        }
        return {res.begin(), res.end()};
    }

    bool exist(vector<vector<char>>& board, string &word) {
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


/* O(m*n*l), O(l) */
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // populate trie
        for (auto &word : words) {
            trie.insert(word);
        }
        m = board.size();
        if (m) {
            n = board[0].size();
        } else {
            n = 0;
        }
        visited = vector<vector<bool>>(m, vector<bool>(n, false));

        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (trie.leaves.count(board[i][j])) {
                    findWords_recur(board, i, j, &trie);
                }
            }
        }


        return {res.begin(), res.end()};
    }


private:
    unordered_set<string> res;
    string cur_wrod;
    vector<vector<bool>> visited;
    int m;
    int n;

    struct trie_node {
        bool is_string = false;
        unordered_map<char, trie_node*> leaves;

        bool insert(string &s) {
            auto p = this;

            for (auto ch : s) {
                if (p -> leaves.find(ch) == leaves.end()) {
                    p -> leaves[ch] = new trie_node;
                }
                p = p -> leaves[ch];
            }

            if (p -> is_string) {
                return false;
            } else {
                p -> is_string = true;
                return true;
            }
        }

        ~trie_node() {
            for (auto &leaf : leaves) {
                if (leaf.second)
                    delete leaf.second;
            }
        }
    } trie;

    void findWords_recur(vector<vector<char>>& board, int i, int j, trie_node *node) {
        if (!node)
            return;

        //cout << i << " " << j << ": " << board[i][j] << endl;
        // find if current ch is in dictionary
        trie_node* next_node = nullptr;
        if (node -> leaves.count(board[i][j])) {
            next_node = node -> leaves[board[i][j]];
            cur_wrod.push_back(board[i][j]);
        } else {
            //cout << "not find leaf:" << board[i][j] << endl;
            return;
        }

        //cout << "next_node " << next_node << endl;
        // valid word
        if (next_node -> is_string) {
            res.insert(cur_wrod);
        }

        visited[i][j] = true;
        const static vector<pair<int, int>> dirs{{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
        for (auto &dir : dirs) {
            auto new_i = i + dir.first;
            auto new_j = j + dir.second;
            if (new_i>=0 && new_i<m && new_j>=0 && new_j<n && !visited[new_i][new_j]) {
                findWords_recur(board, new_i, new_j, next_node);
            }
        }
        visited[i][j] = false;
        cur_wrod.pop_back();
    }
};
