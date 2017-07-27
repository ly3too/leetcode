/*
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
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

class Solution {
public:
    int calculate(string& s) {
        vector<string> tokens;

        // tokenize
        string tmp;
        for (auto &c : s) {
            if (c == ' ') {
                continue;
            }

            if (tmp.empty()) {
                tmp += c;

                /* continue a number */
            } else if (isdigit(c) && isdigit(tmp[0])) {
                tmp += c;

                /* different type */
            } else {
                tokens.emplace_back(move(tmp));
                tmp += c;
            }
        }
        tokens.emplace_back(move(tmp));

        // cout << tokens << endl;

        return evalRPN(getRPN(tokens));
    }

private:
    const char L = 'L';
    const char R = 'R';
    const unordered_map<char, pair<int,char>> operators{{'+',{1,L}},
                            {'-', {1,L}},
                            {'*', {2,L}},
                            {'/', {2,L}},
                            {'%', {3,L}},
                            {'^', {3,R}},
                            {'(', {0,L}},};

    int evalRPN(vector<string>&& tokens) {
        stack<int> values;

        for (auto &token : tokens) {
            if (token.empty())
                continue;

            if(isdigit(token[0]) || token.size()>1) {
                int &&n = stoi(token);
                // is operand
                values.push(n);

            } else {
                // is operator
                auto y = values.top();
                values.pop();
                auto x = values.top();
                values.pop();

                switch (token[0]) {
                case '+':
                    values.push(x+y);
                    break;
                case '-':
                    values.push(x-y);
                    break;
                case '*':
                    values.push(x*y);
                    break;
                case '/':
                    values.push(x/y);
                    break;
                case '%':
                    values.push(x%y);
                    break;
                case '^':
                    values.push(static_cast<int>(pow(x,y)));
                    break;
                default:
                    break;
                }
            }
        }

        return values.empty() ? 0 : values.top();
    }

    vector<string> getRPN(vector<string>& tokens) {
        vector<string> output;
        stack<string> ops;
        for (auto &token : tokens) {
            if (token.empty())
                continue;

            if (token.size()>1 || isdigit(token[0])) {
                output.emplace_back(move(token));

            } else if(token[0] == '(') {
                ops.push(token);

            } else if(token[0] == ')') {
                while((!ops.empty()) && (ops.top()[0] != '(')) {
                    output.emplace_back(move(ops.top()));
                    ops.pop();
                }
                if (!ops.empty()) {
                    ops.pop();
                }

                /*higher priority*/
            } else if (ops.empty() ||
                    operators.at(token[0]).second==L && operators.at(token[0]).first > operators.at(ops.top()[0]).first ||
                    operators.at(token[0]).second==R && operators.at(token[0]).first >= operators.at(ops.top()[0]).first) {
                        ops.push(move(token));

                /*lower priority*/
            } else {
                output.emplace_back(move(ops.top()));
                ops.pop();
                ops.push(token);
            }
        }

        while (!ops.empty()) {
            output.emplace_back(move(ops.top()));
            ops.pop();
        }

        return output;
    }
};


int main() {

    vector<string> in_str = {"", "1 + 2", " 2-1 + 2 ", "(1+(4+5+2)-3)+(6+8)", "5 + ( 6 + ( 5 * 8 ) ^ 2 ) * 2"};
    for (auto &s : in_str) {
        auto res = Solution{}.calculate(s);
        cout << s << " -> " << res << endl;
    }

    return 0;
}
