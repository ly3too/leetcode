/*
Given an encoded string, return it's decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].

Examples:

s = "3[a]2[bc]", return "aaabcbc".
s = "3[a2[c]]", return "accaccacc".
s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
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


/* O(n), O(h) */
class Solution {
public:
    string decodeString(string s) {
        stack<int> opstk;
        stack<string> sstk;

        string tmp;
        string dig;
        for (auto& c : s) {
            if (isdigit(c)) {
                dig += c;

            } else if (c == '[') {
                int n = 0;
                if (!dig.empty()) {
                    n = stoi(dig);
                    dig.clear();
                }
                opstk.push(n);
                sstk.push(move(tmp));

            } else if (c == ']') {

                string str = move(tmp);

                int m = 0;
                if (!opstk.empty()) {
                    m = opstk.top();
                    opstk.pop();
                }

                if (!sstk.empty()) {
                    tmp = move(sstk.top());
                    sstk.pop();
                }
                while (m--) {
                    tmp += str;
                }


            } else {
                tmp += c;

            }

        }

        return tmp;
    }
};
