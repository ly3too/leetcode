/*Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5
*/

#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

/*  */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        if (k <= 1) {
            return head;
        }

        ListNode dum{0};
        dum.next = head;
        int i = 0;
        auto cur = &dum;
        auto last = cur;
        while(cur -> next) {
            ++i;
            cur = cur -> next;
            if (i % k == 0) {
                reverse(last,cur);
                last = cur;
            }
        }

        return dum.next;
    }
private:
    // reverse (head, tail]
    void reverse(ListNode* head, ListNode* &tail) {
        auto last = head->next;
        auto cur = last->next;

        while (cur != tail) {
            last -> next = cur -> next;
            cur -> next = head -> next;
            head -> next = cur;

            cur = last -> next;
        }
        last -> next = cur -> next;
        cur -> next = head -> next;
        head -> next = cur;

        tail = last;
    }
};
