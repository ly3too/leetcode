/*
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/* assume needs to go a nodes before cycle (a >= 0) , b nodes from begin of the cycle to meeting point, c nodes in cycle */
/* after slow pointer enter the cycle, the faster pointer is at most c nodes begind slow pointer, latter, the difference is reduce by one every move,
so they must meet before slow pointer finish a cycle*/
/* assume faster pointer goes k (k>=1)cycle in loop before meeting. So 2(a+b) = a+b+kc => a = kc - b => a = (k-1)c + (c-b), so the distance from head
to begining of the cycle equals to left nodes in cycle + (k-1)c, so one start from the meeting point, and another from head, they will meet at begining point  */

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        auto fast = head;
        auto slow = head;

        while (fast && fast->next) {
            fast = fast -> next -> next;
            slow = slow -> next;

            /* found the cycle */
            if (fast == slow) {
                slow = head;
                while (fast != slow) {
                    slow = slow -> next;
                    fast = fast -> next;
                }
                return slow;
            }
        }

        return nullptr;
    }
};
