/*
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree [1,null,2,3],
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

/* stack solution, push all left node of cur(if any) to stack,
stack top is the first val, set cur to top node's right (if any), pop the top node and re-iterate */
/* O(n), O(h) */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> out;
        stack<TreeNode*> it;

        if (root)
            it.push(root);
        auto cur = root;

        while (!it.empty()) {
            while (cur->left) {
                it.push(cur->left);
                cur = cur -> left;
            }

            out.emplace_back(it.top() -> val);

            if (it.top() -> right) {
                cur = it.top() -> right;
                it.pop();
                it.push(cur);
            } else {
                it.pop();
            }
        }
        return out;
    }
};

/* temprorally set the right most node of every subtree to it's previous level's root  */
/* O(n), O(1) */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> out;

        auto cur = root;

        while (cur) {
            if (cur->left) {
                auto node = cur->left;
                while (node -> right && node -> right != cur) {
                    node = node -> right;
                }
                if (node -> right) {
                    out.emplace_back(cur -> val);
                    node -> right = nullptr;
                    cur = cur -> right;
                } else {
                    node -> right = cur;
                    cur = cur -> left;
                }

            } else {
                out.emplace_back(cur -> val);
                cur = cur -> right;
            }

        }
        return out;
    }
};
