/*
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example:

Input: "babad"

Output: "bab"

Note: "aba" is also a valid answer.
Example:

Input: "cbbd"

Output: "bb"
*/

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

/* Solution1: naive solution
for each C in range[0,N):
    count the palindrome size;
O(n^2) time and O(n) space;
*/

/* solution2 manacher's algorithm O(n),O(n)*/
class Solution {
public:
    string longestPalindrome(string s) {
        int N = static_cast<int>(s.size());
        if (N < 2)
            return s;
        N = 2*N + 1;
        vector<int> LPS(N, 0);
        LPS[1] = 1;
        int R = 2;
        int C = 1;
        int max = 0;
        int max_C = 0;

        for (int i=2; i<N; ++i) {
            if (i%2 == 1) {
                LPS[i] = 1;
            }

            // LPS[i] >= min(LPS[im], R-i)
            if (i < R) {
                LPS[i] = min(LPS[2*C-i], R-i);
            }
            // expand if necessary
            while(LPS[i]+i < N && i-LPS[i] > 0 && (s[(LPS[i]+i+1)/2] == s[(-LPS[i]+i-1)/2]))
                LPS[i] += 2;

            if (max < LPS[i]) {
                max = LPS[i];
                max_C = i;
            }

            // (c) if i+LPS(i) out of LPS range update C and R
            if (i + LPS[i] > R) {
                C = i;
                R = i + LPS[i];
            }
        }
/*
        for (auto x : LPS) {
            cout << x << ", ";
        }
        cout << endl;
        cout << "center: " << max_C << " LPS: " << max << endl;
*/
        string output = s.substr((max_C-max)/2, max);
        return output;
    }
};

int main () {
    vector<string> SV;
    SV.push_back(string("babababababababab"));
    SV.push_back(string(""));
    SV.push_back(string("babad"));
    SV.push_back(string("a"));

    for (auto input : SV) {
        auto output = Solution{}.longestPalindrome(input);
        cout << output << endl;
    }

    return 0;
}
