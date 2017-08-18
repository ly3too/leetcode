/*
The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
*/

/* O(n^2) */
class Solution {
public:
    string getPermutation(int n, int k) {
        // compute n!
        vector<int> nums;
        int nfac = 1;

        for (int i=1; i<=n; ++i) {
            nums.emplace_back(i);
            nfac *= i;
        }
        nfac /= n; //(n-1)!

        string res;
        for (int i=n-1; i>0; --i) {
            int idx = (k-1)/nfac;
            k -= idx*nfac;
            res += to_string(nums[idx]);
            nums.erase(nums.begin() + idx);

            nfac /= i;
        }
        res += to_string(nums[0]);

        return res;
    }
};
