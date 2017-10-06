/*
Given a singly linked list L: L0?L1?…?Ln-1?Ln,
reorder it to: L0?Ln?L1?Ln-1?L2?Ln-2?…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !(head->next))
            return;

        auto fast = head;
        auto slow = head;

        while (fast -> next && fast -> next -> next) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        fast = slow -> next;
        slow -> next = nullptr;

        merge(head, reverse(fast));
    }

private:
    ListNode* reverse (ListNode* head) {
        ListNode* new_head = nullptr;
        while (head) {
            auto tmp = head;
            head = head -> next;
            tmp -> next = new_head;
            new_head = tmp;
        }

        return new_head;
    }

    void merge(ListNode* h1, ListNode* h2) {
        ListNode* tmp;
        while (h1 && h2) {
            tmp = h2;
            h2 = h2 -> next;
            tmp -> next = h1 -> next;
            h1 -> next = tmp;

            h1 = h1 -> next -> next;
        }
        
        if (h2)
            tmp -> next = h2;
    }
};
