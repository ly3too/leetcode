/*
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() < 1 || preorder.size() != inorder.size())
            return nullptr;

        return buildTree_recur(preorder, inorder, 0, preorder.size()-1, 0);
    }

private:
    TreeNode* buildTree_recur(vector<int>& preorder, vector<int>& inorder, int left, int right, int cur) {
        if (left > right)
            return nullptr;
        if (cur >= preorder.size() || cur < 0)
            return nullptr;

        auto new_root = new TreeNode(preorder[cur]);
        auto mid = find_indx(inorder, left, right, preorder[cur]);

        //cout << left << " " << mid << " " << right << endl;

        new_root -> left = buildTree_recur(preorder, inorder, left, mid-1, cur+1);
        new_root -> right = buildTree_recur(preorder, inorder, mid+1, right, cur+mid-left+1);

        return new_root;
    }

    int find_indx(vector<int>& inorder, int left, int right, int val) {
        int i;
        for (i=left; i <= right; ++i) {
            if (inorder[i] == val)
                break;
        }

        return i;
    }

};
