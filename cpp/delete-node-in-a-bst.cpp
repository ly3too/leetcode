/*
Given a root node reference of a BST and a key, delete the node with the given key in the BST.
Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

Search for a node to remove.
If the node is found, delete the node.
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

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (! root)
            return nullptr;

        if (root -> val > key) {
            root -> left = deleteNode(root -> left, key);
        } else if (root -> val < key) {
            root -> right = deleteNode(root -> right, key);
        } else {
            if (!(root -> left)) {
                auto right = root -> right;
                delete root;
                return right;
            } else if (!(root -> right)) {
                auto left = root -> left;
                delete root;
                return left;
            } else {
                auto cur = root -> right;
                auto prev = root;
                while (cur -> left) {
                    prev = cur;
                    cur = cur -> left;
                }

                root -> val = cur -> val;
                if (prev == root) {
                    prev -> right = cur -> right;
                } else {
                    prev -> left = cur -> right;
                }

                delete cur;
                return root;
            }
        }

        return root;
    }
};
