/*
Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,2,3].
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/* O(n),O(1) */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> out;

        auto cur = root;

        while (cur) {
            if (cur -> left) {
                auto node = cur -> left;
                while (node->right && node->right != cur) {
                    node = node -> right;
                }
                if (node -> right) {
                    cur = cur -> right;
                    node -> right = nullptr;

                } else {
                    out.emplace_back(cur->val);
                    node -> right = cur;
                    cur = cur -> left;
                }

            } else {
                out.emplace_back(cur->val);
                cur = cur -> right;

            }
        }

        return out;

    }
};
