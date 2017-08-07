/*
Implement a trie with insert, search, and startsWith methods.

Note:
You may assume that all inputs are consist of lowercase letters a-z.
*/

#include "header.hpp"

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root_ = new TreeNode();
    }

    /** Inserts a word into the trie. */
    void insert(string&& word) {
        auto cur = root_;
        for (auto &c : word) {
            if (cur->node.find(c) != cur->node.end()) {
                cur = cur -> node[c];
            } else {
                cur -> node[c] = new TreeNode();
                cur = cur -> node[c];
            }
        }
        cur -> is_leaf = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string&& word) {
        auto ptr = find(word);
        if (ptr && ptr -> is_leaf) {
            return true;
        }
        return false;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string&& prefix) {
        return find(prefix) != nullptr;
    }

private:
    struct TreeNode {
        unordered_map<char, TreeNode*> node;
        bool is_leaf;
        TreeNode() : is_leaf{false} {};
    };

    TreeNode* root_;

    TreeNode* find(string& word) {
        auto cur = root_;
        for (auto &c : word) {
            if (cur->node.find(c) != cur->node.end()) {
                cur = cur -> node[c];
            } else {
                return nullptr;
            }
        }

        return cur;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
