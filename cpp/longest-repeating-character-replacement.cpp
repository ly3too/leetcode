/*
Given a string that consists of only uppercase English letters, you can replace any letter in the string with another letter at most k times. Find the length of a longest substring containing all repeating letters you can get after performing the above operations.

Note:
Both the string's length and k will not exceed 104.

Example 1:

Input:
s = "ABAB", k = 2

Output:
4

Explanation:
Replace the two 'A's with two 'B's or vice versa.
*/

#include "header.hpp"

class Solution {
public:
    int characterReplacement(string s, int k) {
        /*count the occurance of evry character from i to j*/
        vector<int> cntij(26, 0);
        int len = 0;

        int i = 0, j;
        int times = k; // replaced times
        for (j=0; j<s.size(); ++j) {
            ++cntij[s[j] - 'A'];

            if (s[j] != s[i]) {
                -- times;
            }
            /* used up all chances, update max lenth */
            if (times < 0) {
                len = max (len, j-i);
                while (i<j && times<0) {
                    --cntij[s[i] - 'A'];
                    ++i;
                    times = k - (j - i + 1 - cntij[s[i] - 'A']); // update k from i to j;
                }
            }
        }

        len = max(len, j-i+min(i, times));
        return len;
    }
};
