/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 /* in order traverse, last always keep the last bigest node, cur node should always be bigger than last */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (!root)
            return true;

        if (!isValidBST(root -> left))
            return false;

        if (last && !(last -> val < root -> val))
            return false;

        last = root;

        if (!isValidBST(root -> right))
            return false;

        return true;
    }

private:
    TreeNode* last = nullptr;
};

/* last keep the right most node, cur node shoulde be bigger than it */
/* O(n), O(1) */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        auto cur = root;
        bool isvalid = true;

        while (cur) {
            if (last && !(last->val < cur->val))
                isvalid = false;

            if (cur -> left) {
                auto node = cur -> left;
                while (node && node -> right && node -> right != cur) {
                    node = node -> right;
                }

                if (node -> right) {
                    node -> right = nullptr;
                    last = cur;
                    cur = cur -> right;

                } else {
                    node -> right = cur;
                    cur = cur -> left;

                }

            } else {
                last = cur;
                cur = cur -> right;

            }
        }

        return isvalid;
    }

private:
    TreeNode* last = nullptr;
};
