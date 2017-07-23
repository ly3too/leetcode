/*
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
*/

#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

/* using stack */
class Solution {
public:
    int longestValidParentheses(string s) {
      auto max_len = 0;
      stack<int> my_stack{};
      my_stack.push(-1);

      int i = 0;
      for (auto x : s) {

        if (x == ')' && !my_stack.empty()) {
          my_stack.pop();
          if (!my_stack.empty())
            max_len = max(max_len, i-my_stack.top());
          else
            my_stack.push(i);

          ++i;

        } else if(x == '(') {
            my_stack.push(i);

            ++i;
        }

      }

      return max_len;
    }
};

/* using dynamic programing */
