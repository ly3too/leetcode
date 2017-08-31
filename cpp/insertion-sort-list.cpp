/*
Sort a linked list using insertion sort.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 /* O(n^2) O(1)*/
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        auto dumy = new ListNode{numeric_limits<int>::min()};
        dumy -> next = head;
        auto cur = head;
        auto prev = dumy;

        while (cur) {
            auto pos = find_pos(dumy, cur);
            if (pos -> next != cur) {
                prev -> next = cur -> next; // remvoe cur

                // insert cur;
                cur -> next = pos -> next;
                pos -> next = cur;

                cur = prev -> next;
                
            } else {
                prev = cur;
                cur = cur -> next;
            }

        }

        return dumy -> next;
    }

private:
    ListNode* find_pos(ListNode* head, ListNode* cur) { // return the the node to be insterd after;
        auto prev = head;
        while (prev->next && prev->next->val < cur->val) {
            prev = prev -> next;
        }
        return prev;
    }
};
