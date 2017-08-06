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

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
      vector<int> out;
      stack<TreeNode*> stk;
      if (root)
        stk.push(root);
      TreeNode* cur = root;

      while (!stk.empty()) {
        if (cur -> left) {
          stk.push(cur);
          cur = cur -> left;

        } else if (cur->right) {
          cur = cur -> 

        }

      }

    }
};
