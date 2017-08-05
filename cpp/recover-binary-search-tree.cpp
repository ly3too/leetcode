/*
Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
*/

#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <iomanip>
#include <stack>
#include <ctime>
#include <ctype.h>
#include <sstream>
#include <map>
#include <cmath>
#include <unordered_map>
#include <typeinfo>
#include "print_container.hpp"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/* inorder transvers the tree using Morris Traversal, check every two adjacent values */
/* O(n), O(1) */
class Solution {
public:
    void recoverTree(TreeNode* root) {
        auto cur = root;
        TreeNode* err1 = nullptr;
        TreeNode* err2 = nullptr;
        TreeNode* prev = nullptr;

        while (cur) {
            if (cur->left) {
                auto node = cur->left;
                while (node -> right && node -> right != cur) {
                    node = node -> right;
                }
                if (node -> right) {
                    check_err(prev, cur, err1, err2);
                    prev = cur;
                    node -> right = nullptr;
                    cur = cur -> right;
                } else {
                    node -> right = cur;
                    cur = cur -> left;
                }

            } else {
                check_err(prev, cur, err1, err2);
                prev = cur;
                cur = cur -> right;
            }
        }

        if (err1 && err2)
            swap(err1->val, err2->val);
    }

private:
    void check_err(TreeNode* &prev, TreeNode* &cur, TreeNode* &err1, TreeNode* &err2) {
        if (prev && prev->val > cur->val) {
            if (!err1) {
                err1 = prev;
            }
            err2 = cur;
        }
    }
};
