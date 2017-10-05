/* merg sort or quick sort */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 /* merge sort, fast slow pointer to find middle point, O(nlogn), O(1) */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        auto fast = head;
        auto slow = head;

        while (fast->next && fast->next->next) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        auto second = slow -> next;
        slow -> next = nullptr;

        return merge_lists(sortList(head), sortList(second));
    }

private:
    ListNode* merge_lists(ListNode* first, ListNode* second) {
        if (first == nullptr)
            return second;
        if (second == nullptr)
            return first;

        ListNode* head;
        if (first->val < second->val) {
            head = first;
            first = first -> next;
        } else {
            head = second;
            second = second -> next;
        }

        auto cur = head;
        while (first && second) {
            if (first->val < second->val) {
                cur -> next = first;
                first = first -> next;
            } else {
                cur -> next = second;
                second = second -> next;
            }
            
            cur = cur -> next;
        }

        cur -> next = first ? first : second;

        return head;
    }
};
