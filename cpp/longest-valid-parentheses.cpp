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
class Solution {
public:
    int longestValidParentheses(string s) {
      if (s.size() <= 1)
        return 0;

      auto max_len = 0;
      vector<int> mv(s.size(), 0);

      auto last_c = s[0];
      for (int i=1; i < s.size(); ++i) {
        auto c = s[i];
        if (c == ')') {
          if (last_c == '(') {
            if ()

          } else if (last_c == ')') {

          }

          last_c = c;
        } else if (c == ')') {

          last_c = c;
        } else {
          mv[i] = mv[i-1];
        }

      }

      return max_len;
    }
};
