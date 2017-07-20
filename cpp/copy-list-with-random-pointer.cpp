/*
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.
*/

#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>

using namespace std;


struct RandomListNode {
     int label;
     RandomListNode *next, *random;
     RandomListNode():label(0), next(NULL), random(NULL) {};
     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

/* duplicate node and insert to the same place O(n),O（1） */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {

        if (!head) {
            return NULL;
        }

        // copy and insert node into original list
        for (auto cur=head; cur; cur=cur->next->next) {
            RandomListNode *new_node = new RandomListNode(cur -> label);
            new_node -> next = cur -> next;
            cur -> next = new_node;
        }

        // update random ptr
        for (auto cur=head; cur; cur=cur->next->next) {
            if (cur -> random) {
                cur -> next -> random = cur -> random -> next;
            }
        }

        // decouple
        auto new_list = head -> next;
        auto cur=head;
        for (auto tmp = cur->next; tmp->next; tmp = cur->next) {
            cur -> next = cur -> next -> next;
            tmp -> next = tmp -> next -> next;
            cur=cur->next;
        }
        cur -> next = cur -> next -> next;

        return new_list;
    }
};

void printlist(RandomListNode* list) {
    auto tmp = list;
    while(tmp) {
        cout << setw(3) << tmp->label << ' ';
        tmp = tmp -> next;
    }
    cout << endl;

    tmp = list;
    while(tmp) {
        cout << setw(3) << '|' << ' ';
        tmp = tmp -> next;
    }
    cout << endl;

    tmp = list;
    while(tmp) {
        if (tmp->random)
            cout << setw(3) << tmp -> random -> label << ' ';
        else
            cout << setw(3) << "NA" << ' ';
        tmp = tmp -> next;
    }
    cout << endl;
}

int main () {
    const auto SIZE = 20;
    RandomListNode list[SIZE];
    RandomListNode *input_list=list;

    srand(time(NULL));

    for (auto i=0; i<SIZE-1; ++i) {
        list[i].next = &list[i+1];
        list[i].label = i;
        if (rand()%10>4)
            list[i].random = &list[rand()%SIZE];
    }
    list[SIZE-1].next = NULL;
    list[SIZE-1].label = SIZE-1;

    cout << "original : " << endl;
    printlist(input_list);

    auto output = Solution{}.copyRandomList(input_list);

    cout << "after : " << endl;
    printlist(input_list);
    cout << "output :" << endl;
    printlist(output);

    return 0;
}
