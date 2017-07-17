/*
Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
*/

#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

// KMP algorithm: O(n), O(m)
class Solution {
public:
    int strStr(string haystack, string needle) {
        auto N = haystack.size();
        auto M = needle.size();
        if (N < M)
            return -1;
        if (M < 1)
            return 0;
        auto lps = preproceses(needle);
        int i = 0; // for haystack
        int j = 0; // for needle
        while (i < N) {
            if (haystack[i] != needle[j]) {
                if (j > 0)
                    j = lps[j-1];
                else
                    ++i;
            } else {
                ++i;
                ++j;
            }

            if (j == M) {
                return i-M;
                j = lps[j-1];
            }
        }

        return -1;
    }
private:
    /* find the max prefix sufix */
    vector<int> preproceses(string &needle) {
        auto M = needle.size();
        vector<int> lps(M);
        lps[0] = 0;
        int i = 1;
        int len = 0;
        while (i < M) {
            if (needle[i] == needle[len]) {
                lps[i++] = ++len;
            } else if (len > 0) {
                len = lps[len-1];
            } else {
                lps[i++] = 0;
            }
        }
        return lps;
    }
};

// KMP algorithm: O(n), O(m)
class Solution2 {
public:
    vector<int> strStr(string haystack, string needle) {
        auto N = haystack.size();
        auto M = needle.size();
        vector<int> found;
        if (M < 1)
            return found;
        if (N < M)
            return found;
        auto lps = preproceses(needle);
        int i = 0; // for haystack
        int j = 0; // for needle
        while (i < N) {

            // cout << "i = " << i << ", j = " << j << endl;

            if (haystack[i] != needle[j]) {
                if (j > 0)
                    j = lps[j-1];
                else
                    ++i;
            } else {
                ++i;
                ++j;
            }

            if (j == M) {
                found.push_back(i-M);
                j = lps[j-1];
            }
        }

        return found;
    }
private:
    /* find the max prefix sufix */
    vector<int> preproceses(string &needle) {
        auto M = needle.size();
        vector<int> lps(M);
        lps[0] = 0;
        int i = 1;
        int len = 0;
        while (i < M) {
            if (needle[i] == needle[len]) {
                lps[i++] = ++len;
            } else if (len > 0) {
                len = lps[len-1];
            } else {
                lps[i++] = 0;
            }
        }
/*
        for (auto x : lps)
            cout << x << " ";
        cout << endl;
*/
        return lps;
    }
};


int main () {
    string haystack{"mississippi"};
    string needle{"issi"};
    // string haystack{"aaaaaaaa"};
    // string needle{"aaa"};

    auto output = Solution2{}.strStr(haystack, needle);
    cout << needle << endl;
    cout << haystack << endl;
    int i = 0;
    for (auto x : output) {
        while (i++ < x)
            cout << ' ';
        cout << '^';
    }
    cout << endl;

    for (auto x : output) {
        cout << x << " ";
    }

    return 0;
}

/*
int main () {
    string haystack{"mississippi"};
    string needle{"issip"};

    auto output = Solution{}.strStr(haystack, needle);
    cout << needle << endl;
    cout << haystack << endl;
    int i = 0;

    while (i++ < output)
        cout << ' ';
    cout << '^';
    cout << endl;

    cout << output << endl;


    return 0;
}
*/
