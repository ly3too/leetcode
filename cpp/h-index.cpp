/*
Given an array of citations (each citation is a non-negative integer) of a researcher, write a function to compute the researcher's h-index.

According to the definition of h-index on Wikipedia: "A scientist has index h if h of his/her N papers have at least h citations each, and the other N − h papers have no more than h citations each."
*/

/* sorting O(nlog(n)), O(1) */
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), greater<int>());

        int h;
        for (h=0; i<citations.size(); ++h) {
            if (h >= citations[h]) {
                break;
            }
        }

        return h;
    }
};

/* counting sort O(n), O(n) */
class Solution {
public:
    int hIndex(vector<int>& citations) {
        auto N = citations.size();
        vector<int> cnt(N+1, 0);

        for (const auto &x : citations) {
            if (x >= N) {
                ++cnt[N];
            } else {
                ++cnt[x];
            }
        }

        int h = 0;
        for (int i=N; i>=0; --i) {
            h += cnt[N];

            if (i <= h) {
                return i;
            }
        }

        return h;
    }
};
