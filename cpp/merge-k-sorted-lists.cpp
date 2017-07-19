/*
    Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
*/

#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {;}
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/* merge 2 by 2, O(nlogk), O(1) */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int front = 0;
        int tail = static_cast<int>(lists.size()) - 1;
        if (tail < 0)
            return NULL;
        while(tail > 0) {
            lists[front] = merge2(lists[front], lists[tail]);
            ++front;
            --tail;

            if(front >= tail) {
                front = 0;
            }
        }

        return lists[0];
    }

private:
    ListNode* merge2(ListNode* node1, ListNode* node2) {
        ListNode dum(0);
        auto cur = &dum;

        while (node1 || node2) {
            if (node1 && node2) {
                if (node1->val <= node2->val ) {
                    cur -> next = node1;
                    node1 = node1 -> next;
                } else {
                    cur -> next = node2;
                    node2 = node2 -> next;
                }

            } else if (node1) {
                cur -> next = node1;
                node1 = node1 -> next;

            } else {
                cur -> next = node2;
                node2 = node2 -> next;
            }

            cur = cur -> next;
        }

        return dum.next;
    }
};

/* solution2 use min heap O(k+nlogk), O(k) */
class Solution2 {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode dum(0);
        auto cur = &dum;
        priority_queue<ListNode*, vector<ListNode*>, grater> mypq;

        for (auto &x : lists) {
            if (x)
                mypq.emplace(x);
        }
        while (!mypq.empty()) {
            auto tmp = mypq.top();
            mypq.pop();
            cur -> next = tmp;
            cur = cur -> next;
            tmp = tmp -> next;
            if (tmp)
                mypq.emplace(tmp);
        }

        return dum.next;
    }
private:
    struct grater{
        bool operator()(ListNode* &node1, ListNode* &node2) {
            return node1 -> val > node2 -> val;
        }
    };
};


ListNode *add_to_list(ListNode* node, int val){
    ListNode *tmp = new ListNode(val);
    tmp -> next = node;
    return tmp;
}

int main () {
    vector<ListNode *> lists;
    for (int i=0; i<10; ++i) {
        ListNode *tmp_list = NULL;
        auto n = rand()%40;
        vector<int> tmp;
        for(int j=0; j<n; ++j) {
            tmp.push_back(rand()%100);
        }
        sort(tmp.begin(), tmp.end());

        while(!tmp.empty()) {
            tmp_list = add_to_list(tmp_list, tmp.back());
            tmp.pop_back();
        }

        lists.push_back(tmp_list);
    }

    cout << "before merge : " << endl;
    for (auto node : lists) {
        while (node) {
            cout << node->val << ' ';
            node = node -> next;
        }
        cout << endl;
    }

    auto merged = Solution{}.mergeKLists(lists);

    cout << "after merge : " << endl;
    while(merged) {
        cout << merged->val << ' ';
        merged = merged -> next;
    }
    cout << endl;

    return 0;
}
