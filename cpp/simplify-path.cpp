/*
Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
click to show corner cases.

Corner Cases:
Did you consider the case where path = "/../"?
In this case, you should return "/".
Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
In this case, you should ignore redundant slashes and return "/home/foo".
*/

#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <list>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        list<string> names;
        auto&& tokens = split(path, '/');
        for (auto &token : tokens) {
            if (token == "..") {
                if (!names.empty()) {
                    names.pop_back();
                }
            } else if (token != "." && (!token.empty())) {
                names.push_back(move(token));
            }
        }

        if (names.empty()) {
            return "/";
        }

        string s{};
        for (auto &name : names) {
            s += "/";
            s += name;
        }

        return s;
    }

private:
    list<string> split(string &s, char delim) {
        stringstream ss{s};
        string token;
        list<string> tokens;
        while (getline(ss, token, delim)) {
            tokens.push_back(move(token));
        }

        return tokens;
    }
};

int main () {
    vector<string> SV;
    SV.push_back(string("/"));
    SV.push_back(string("//"));
    SV.push_back(string("/../"));
    SV.push_back(string("/a/./b/../../c/"));
    SV.push_back(string("/home/"));

    for (auto input : SV) {
        cout << input << " -> ";
        auto output = Solution{}.simplifyPath(input);
        cout << output << endl;
    }

    return 0;
}
