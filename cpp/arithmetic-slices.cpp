/*
A sequence of number is called arithmetic if it consists of at least three elements and if the difference between
any two consecutive elements is the same.
*/

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int res = 0;
        for (int i=0; i+2 < A.size(); ++i) {
            auto start = i;

            while (i+2 < A.size() && (A[i]+A[i+2] == 2*A[i+1])) {
                res += i-start + 1;
                ++i;
            }
        }

        return res;
    }
};
