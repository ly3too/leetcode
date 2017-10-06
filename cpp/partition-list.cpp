/*Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 /* O(n), O(1) */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode dum{0};
        auto bigger = &dum;
        ListNode dum2{0};
        auto smaller = &dum2;

        while (head) {
            if (head -> val < x) {
                smaller -> next = head;
                smaller = smaller -> next;
            } else {
                bigger -> next = head;
                bigger = bigger -> next;
            }
            head = head -> next;
        }

        bigger -> next = nullptr;

        smaller -> next = dum.next;

        return dum2.next;
    }
};
