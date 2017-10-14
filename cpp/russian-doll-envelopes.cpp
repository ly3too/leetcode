/*
You have a number of envelopes with widths and heights given as a pair of integers (w, h).
One envelope can fit into another if and only if both the width and height of one envelope
is greater than the width and height of the other envelope.

*/

/* O(log(n)) , O(1)*/
class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        using pr_t = pair<int, int>;

        auto cmp = [] (pr_t &p1, pr_t &p2) {
            return p1.first == p2.first ? p1.second > p2.second : p1.first < p2.first;};

        sort(envelopes.begin(), envelopes.end(), cmp);

        vector<int> res;
        for (auto &enve : envelopes) {
            auto target = enve.second;

            auto it = lower_bound(res.begin(), res.end(), target);

            if (it == res.end()) {
                res.emplace_back(target);
            } else {
                *it = target;
            }
        }

        return res.size();
    }
};
