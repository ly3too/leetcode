/*
You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Follow up:
What if you cannot modify the input lists? In other words, reversing the lists is not allowed.
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


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int N1 = 0;
        int N2 = 0;
        auto li_tmp = l1;
        while(li_tmp) {
            ++ N1;
            li_tmp = li_tmp -> next;
        }
        li_tmp = l2;
        while(li_tmp) {
            ++ N2;
            li_tmp = li_tmp -> next;
        }

        if (N1 == 0)
            return l2;
        if (N2 == 0)
            return l1;

        ListNode* result;
        if (N1 > N2) {
            result = sum(l1, l2, N1-N2);
        } else {
            result = sum(l2, l1, N2-N1);
        }

        return result;
    }

private:
    ListNode* sum(ListNode* l1, ListNode* l2, int diff) {
        auto res = new ListNode{1};
        res -> next = l1;

        auto brw = res;
        auto cur = l1;

        while (diff > 0 && cur) {
            cur -> val += 1;
            if (cur -> val > 10) {
                cur -> val %= 10;
                brw = cur;
            } else if (cur -> val == 10) {
                cur -> val %= 10;
            } else {
                while (brw != cur) {
                    brw -> val -= 1;
                    if (brw -> val < 0) {
                        brw -> val += 10;
                    }
                    brw = brw -> next;
                }
            }
            cur = cur -> next;
            --diff;
        }

        auto cur2 = l2;
        while (cur && cur2) {
            cur -> val = cur->val + cur2->val + 1;
            if (cur -> val > 10) {
                cur -> val %= 10;
                brw = cur;
            } else if (cur -> val == 10) {
                cur -> val %= 10;
            } else {
                while (brw != cur) {
                    brw -> val -= 1;
                    if (brw -> val < 0) {
                        brw -> val += 10;
                    }
                    brw = brw -> next;
                }
            }

            cur = cur -> next;
            cur2 = cur2 -> next;
        }
        while (brw != cur) {
            brw -> val -= 1;
            if (brw -> val < 0) {
                brw -> val += 10;
            }
            brw = brw -> next;
        }


        if (res->val == 0) {
            delete res;
            return l1;
        } else {
            return res;
        }
    }
};

void print_list(ListNode* l1) {
    while (l1) {
        cout << l1 -> val << "->";
        l1 = l1 -> next;
    }
    cout << "NULL" << endl;
}

int main () {
    const auto SIZE = 1;
    const auto SIZE2 = 0;
    ListNode list[SIZE](0);
    ListNode *input_list1=list;
    ListNode list2[SIZE2](0);
    ListNode *input_list2=list2;

    srand(time(NULL));

    for (auto i=0; i<SIZE-1; ++i) {
        list[i].next = &list[i+1];
        list[i].val = rand()%10;
    }
    list[SIZE-1].next = NULL;
    list[SIZE-1].val = rand()%10;

    for (auto i=0; i<SIZE2-1; ++i) {
        list2[i].next = &list2[i+1];
        list2[i].val = rand()%10;
    }
    list2[SIZE2-1].next = NULL;
    list2[SIZE2-1].val = rand()%10;

    cout << "l1: ";
    print_list(input_list1);
    cout << "l2: ";
    print_list(input_list2);
    cout << "res: ";
    auto res = Solution{}.addTwoNumbers(input_list1, input_list2);
    print_list(res);

    return 0;
}
