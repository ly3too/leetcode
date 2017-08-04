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
