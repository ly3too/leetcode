/*
Your task is to calculate ab mod 1337 where a is a positive integer and b is an extremely large positive integer given in the form of an array.
*/

class Solution {
public:
    int superPow(int a, vector<int>& b) {
        int n = b.size();
        int a_10 = a; // a^(10^k), k is the k-th last index of b;
        int res = 1;
        while (--n >= 0) {
            res *= pow(a_10, b[n]);
            res %= MOD;
            a_10 = pow(a_10, 10);
        }

        return res;
    }
    Solution() : MOD(1337) {}

private:
    const int MOD;
    int pow(int a, int b) {
        assert(a>=0 && b>=0);
        if (b == 0)
            return 1;
        if (b == 1)
            return a % MOD;
        int res = pow(a, b>>1);
        res *= res;
        res %= MOD;

        if (b % 2) {
            res *= (a % MOD);
            res %= MOD;
        }
        return res;
    }
};
