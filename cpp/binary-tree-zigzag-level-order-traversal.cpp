/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],

return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
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

 /* usign deque, O(n), O(n), breadth first search*/
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        deque<TreeNode*> deq;

        if (root)
            deq.push_back(root);

        int level = 0;

        while (!deq.empty()) {
            vector<int> cur_level;
            auto size = deq.size();

            if (level % 2 ==0) {
                for (int i=0; i<size; ++i) {
                    auto node = deq.front();
                    deq.pop_front();

                    cur_level.emplace_back(node -> val);
                    if (node->left) {
                        deq.push_back(node -> left);
                    }
                    if (node -> right) {
                        deq.push_back(node -> right);
                    }
                }
            } else {
                for (int i=0; i<size; ++i) {
                    auto node = deq.back();
                    deq.pop_back();

                    cur_level.emplace_back(node -> val);
                    if (node->right) {
                        deq.push_front(node -> right);
                    }
                    if (node -> left) {
                        deq.push_front(node -> left);
                    }
                }
            }

            res.emplace_back(move(cur_level));
            ++level;
        }

        return res;
    }
};
