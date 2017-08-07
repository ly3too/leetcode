/*
Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [3,2,1].
*/

#include "header.hpp"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


/* O(n), O(h) */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
      vector<int> out;
      stack<TreeNode*> stk;
      stack<TreeNode*> stk2;
      if (!root)
        return out;

      TreeNode* cur = root;

        do {
            while (cur) {
                stk.push(cur);
                cur = cur -> left;
            }
            auto node = stk.top();
            stk.pop();
            if (node -> right) {
                stk2.push(node);
                cur = node -> right;

            } else {
                out.emplace_back(node -> val);

            }

            while (!stk2.empty() && stk2.top() -> right == node) {
                out.emplace_back(stk2.top()->val);
                node = stk2.top();
                stk2.pop();
            }

        } while (!stk.empty() || cur);

        return out;
    }
};
