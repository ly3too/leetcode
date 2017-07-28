/*
Given a nested list of integers represented as a string, implement a parser to deserialize it.

Each element is either an integer, or a list -- whose elements may also be integers or other lists.

Note: You may assume that the string is well-formed:

String is non-empty.
String does not contain white spaces.
String contains only digits 0-9, [, - ,, ].
*/

#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <iomanip>
#include <stack>
#include <ctime>
#include <ctype.h>
#include <sstream>
#include <map>
#include <cmath>
#include <unordered_map>
#include <typeinfo>
#include "print_container.hpp"

using namespace std;


 // This is the interface that allows for creating nested lists.
 // You should not implement it, or speculate about its implementation
class NestedInteger {
    public:
    // Constructor initializes an empty nested list.
    NestedInteger(){}

    // Constructor initializes a single integer.
    NestedInteger(int value){}

    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const{}

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const{}

    // Set this NestedInteger to hold a single integer.
    void setInteger(int value){}

    // Set this NestedInteger to hold a nested list and adds a nested integer to it.
    void add(const NestedInteger &ni){}

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const{}
};


/* O(n), O(n) */
class Solution {
public:
    NestedInteger deserialize(string s) {
        if (s.empty())
            return NestedInteger();

        string tmp;
        stack<string> tokens;
        stack<int> stk;
        for (auto& c : s) {
            if (c == ',') {
                continue;

            } else if (c == '[') {
                if (!tmp.empty())
                    tokens.push(move(tmp));
                // tmp += c;


            } else if (c == ']') {
                /*
                tokens.push(move(tmp));
                while (!tokens.empty() && tokens.top()[0] != '[') {
                    int val = stoi(tokens.top());
                    stk.push(NestedInteger(val));
                    tokens.pop();
                }
                tokens.pop();
                */
                if (tmp.empty()) {
                    stk.push(stoi(tokens.top()));
                    tokens.pop();
                } else {
                    stk.push(stoi(tmp));
                    tmp.clear();
                }


            } else {
                tmp += c;

            }
        }
        if (!tmp.empty()) {
            return NestedInteger(stoi(tmp));
        }

        auto&& res = NestedInteger();
        auto&& l1 = NestedInteger(stk.top());
        res.add(l1);
        // cout << stk.top() << " ";
        stk.pop();
        //auto* last = &l1;
        while(!stk.empty()) {
            auto&& tmp = NestedInteger(stk.top());
            // cout << stk.top() << " ";
            stk.pop();
            res.add(tmp);
            //last -> add(tmp);
            //last = &tmp;
        }

        return res;
    }
};

int main() {
    vector<string> sv {"", "123", "[123,[456,[789]]]"};

    for (auto& s: sv) {
        Solution{}.deserialize(s);
        cout << endl;
    }

    return 0;
}
