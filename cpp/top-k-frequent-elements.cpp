/*
Given a non-empty array of integers, return the k most frequent elements.

For example,
Given [1,1,1,2,2,3] and k = 2, return [1,2].
*/

/* priority queue solution, O(nlogk), O(n) */
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cnts;
        for (auto &n : nums) {
            ++cnts[n];
        }

        using pair_type = pair<int, int>;
        auto cmp = [](pair_type &pl, pair_type &pr) {return pl.second > pr.second;};
        priority_queue<pair_type, vector<pair_type>, decltype(cmp)> heap(cmp);
        for (auto &p : cnts) {
            heap.emplace(p);
            if (heap.size() > k) {
                heap.pop();
            }
        }

        vector<int> res;
        while(!heap.empty()) {
            res.emplace_back(heap.top().first);
            heap.pop();
        }

        reverse(res.begin(), res.end());

        return res;
    }
};

/* quick partition , O(n~n^2), expected O(n); O(n)*/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cnts;
        for (auto &n : nums) {
            ++cnts[n];
        }

        vector<pair<int, int>> vect;
        for (auto &p : cnts) {
            vect.emplace_back(p);
        }

        using pair_type = pair<int, int>;
        auto cmp = [](pair_type &pl, pair_type &pr) {return pl.second > pr.second;};
        nth_element(vect.begin(), vect.begin()+k-1, vect.end(), cmp);

        vector<int> res;
        for (auto it = vect.begin(); it != vect.begin()+k; ++it) {
            res.emplace_back(it -> first);
        }

        return res;
    }
};
