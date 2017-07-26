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
//#include "print_container.hpp"

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
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
                default:
                    break;
                }
            }
        }

        return values.empty() ? 0 : values.top();
    }
};



int main() {
    vector<vector<string>> vvs;
    vector<string> in_str = {"", "1 2 +", "2 -1 + 3 *", "4 13 5 / +"};
    for (auto& s : in_str) {
        stringstream ss{move(s)};
        string tmp;
        vector<string> vs_tmp;
        while(getline(ss, tmp, ' ')) {
            vs_tmp.emplace_back(move(tmp));
        }
        vvs.emplace_back(move(vs_tmp));
    }

    //cout << string{"hello"} << endl;
    for (auto& vs : vvs) {
        cout << " -> " << Solution{}.evalRPN(vs) << endl;
    }
}
