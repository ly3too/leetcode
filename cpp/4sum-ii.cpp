/*
Given four lists A, B, C, D of integer values, compute how many tuples (i, j, k, l)
 there are such that A[i] + B[j] + C[k] + D[l] is zero.

To make problem a bit easier, all A, B, C, D have same length of N where 0 ≤ N ≤ 500.
All integers are in the range of -228 to 228 - 1 and the result is guaranteed to be at most 231 - 1.
*/

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int res = 0;
        unordered_map<int, int> lookup;
        for (auto &a : A) {
            for (auto &b : B) {
                ++lookup[a+b];
            }
        }

        for (auto &c : C) {
            for (auto &d : D) {
                if (lookup.find(-c-d) != lookup.end()) {
                    res += lookup[-c-d];
                }
            }
        }
        
        return res;
    }
};
