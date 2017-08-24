/*
Given a singly linked list, return a random node's value from the linked list. Each node must have the same probability of being chosen.

Follow up:
What if the linked list is extremely large and its length is unknown to you? Could you solve this efficiently without using extra space?
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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) : head_{head} {
        random = uniform_int_distribution<int>(0, numeric_limits<int>::max());
    }

    /** Returns a random node's value. */
    int getRandom() {
        ListNode* cur = head_;
        auto val = head_ -> val;
        cur = cur->next;
        int size = 1;
        while (cur) {
            if (random(generator) % ++size == 0) {
                val = cur->val;
            }

            cur = cur -> next;
        }

        return val;
    }
private:
    ListNode* head_;
    default_random_engine generator;
    uniform_int_distribution<int> random;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */

 class Solution {
 public:
     /** @param head The linked list's head.
         Note that the head is guaranteed to be not null, so it contains at least one node. */
     Solution(ListNode* head) : head_{head}, cur_{head}, size_{0} {
         ListNode* cur = head_;
         generator = default_random_engine{time(0)};

         while (cur) {
             ++size_;
             cur = cur -> next;
         }

         random = uniform_int_distribution<int>(0, size_-1);
     }

     /** Returns a random node's value. */
     int getRandom() {
         int cnt = random(generator);
         while (cnt-- > 0) {
             cur_ = cur_ -> next;

             if (cur_ == nullptr) {
                 cur_ = head_;
             }
         }

         return cur_ -> val;
     }
 private:
     int size_;
     ListNode* head_;
     ListNode* cur_;
     default_random_engine generator;
     uniform_int_distribution<int> random;
 };
