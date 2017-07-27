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


class BSTIterator {
public:
    BSTIterator(TreeNode *root) : root{root} {

        auto p_cur = root;
        while (p_cur) {
            track.push(p_cur);
            p_cur = p_cur -> left;
        }

    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !track.empty();
    }

    /** @return the next smallest number */
    int next() {
        auto pcur = track.top();
        auto val = pcur -> val;
        track.pop();
        if (pcur -> right){
            pcur = pcur -> right;
            while (pcur) {
                track.push(pcur);
                pcur = pcur -> left;
            }
        }

        return val;
    }

private:
    stack<TreeNode*> track;
    TreeNode* root;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */

int main() {

    BSTIterator i{NULL};

     return 0;
}
