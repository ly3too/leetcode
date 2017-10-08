/*
Given inorder and postorder traversal of a tree, construct the binary tree.

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

 /* O(nlogn), O(1) */
 class Solution {
 public:
     TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
         if (postorder.size() < 1 || postorder.size() != inorder.size())
             return nullptr;

         return buildTree_recur(postorder, inorder, 0, postorder.size()-1, postorder.size()-1);
     }

 private:
     TreeNode* buildTree_recur(vector<int>& postorder, vector<int>& inorder, int left, int right, int cur) {
         if (left > right)
             return nullptr;
         if (cur >= postorder.size() || cur < 0)
             return nullptr;

         auto new_root = new TreeNode(postorder[cur]);
         auto mid = find_indx(inorder, left, right, postorder[cur]);

         //cout << left << " " << mid << " " << right << endl;

         new_root -> left = buildTree_recur(postorder, inorder, left, mid-1, cur-1-(right-mid));
         new_root -> right = buildTree_recur(postorder, inorder, mid+1, right, cur-1);

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
