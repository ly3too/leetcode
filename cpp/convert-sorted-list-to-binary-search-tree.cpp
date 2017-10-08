/*
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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

 /* construct in inorder traverse, keep updating head to next node, O(n), O(logn) */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        auto curr = head;
        int n = 0;
        while (curr) {
            curr = curr->next;
            ++n;
        }
        return BuildBSTFromSortedDoublyListHelper(&head, 0, n-1);
    }

private:
    TreeNode * BuildBSTFromSortedDoublyListHelper(ListNode **head, int s, int e) {
        if (s > e)
            return nullptr;

        auto mid = (s+e+1) / 2;

        /* construct left first */
        auto left = BuildBSTFromSortedDoublyListHelper(head, s, mid-1);

        /* parent */
        auto cur = new TreeNode((*head) -> val);
        cur -> left = left;

        *head = (*head) -> next;

        /* right */
        cur -> right = BuildBSTFromSortedDoublyListHelper(head, mid+1, e);

        return cur;
    }
};
