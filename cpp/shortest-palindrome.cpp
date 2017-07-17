/*
Given a string S, you are allowed to convert it to a palindrome by adding characters in front of it. Find and return the shortest palindrome you can find by performing this transformation.

For example:

Given "aacecaaa", return "aaacecaaa".

Given "abcd", return "dcbabcd".
*/

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

/* manacher's algo to find largest
palindrome starts with the first or ends with the last */
class Solution {
public:
    string shortestPalindrome(string s) {
        int N = static_cast<int>(s.size());
        if (N < 2)
            return s;
        N = 2*N + 1;
        vector<int> LPS(N, 0);
        LPS[1] = 1;
        int R = 2;
        int C = 1;
        int max = 1;
        int max_C = 1;

        for (int i=2; i<N; ++i) {
            if (i%2 == 1) {
                LPS[i] = 1;
            }

            // LPS[i] >= min(LPS[im], R-i)
            if (i < R) {
                LPS[i] = min(LPS[2*C-i], R-i);
            }
            // expand if necessary
            while(LPS[i]+i < N && i-LPS[i] > 0 && (s[(LPS[i]+i+1)/2] == s[(-LPS[i]+i-1)/2])) {
                LPS[i] += 2;

                // uncomment this to get from both front and end
                /* if ((LPS[i]+i == N-1 || i-LPS[i] == 0) && max < LPS[i]) { */
                if ( i-LPS[i] == 0 && max < LPS[i]) {
                    max = LPS[i];
                    max_C = i;
                }
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
        if (max_C >= N/2) {
            /* append at the end */
            string substr = s.substr(0, s.size()-max);
            reverse(substr.begin(), substr.end());
            return s+substr;

        } else {
            /* insert at the begining */
            string substr = s.substr((max_C+max)/2, s.size()-max);
            reverse(substr.begin(), substr.end());
            return substr+s;
        }

    }
};

int main () {
    vector<string> SV;
    SV.push_back(string("baba"));
    SV.push_back(string(""));
    SV.push_back(string("babad"));
    SV.push_back(string("a"));
    SV.push_back(string("aac1ecaaaa"));
    SV.push_back(string("abcd"));

    for (auto input : SV) {
        auto output = Solution{}.shortestPalindrome(input);
        cout << output << endl;
    }

    return 0;
}
