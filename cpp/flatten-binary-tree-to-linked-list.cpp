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
    void flatten(TreeNode* root) {
        if (!root)
            return;

        flatten(root -> right);
        flatten(root -> left);
        root -> right = new_root;
        root -> left = nullptr;
        new_root = root;

    }

private:
    TreeNode* new_root = nullptr;
};

/* double linklist */
class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root)
            return;

        flatten(root -> right);
        flatten(root -> left);
        root -> right = new_root;

        root -> left = nullptr;
        if (root -> right) {
            root -> right -> left = root;
        }

        new_root = root;

    }

private:
    TreeNode* new_root = nullptr;
};
