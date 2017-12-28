/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most k transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

Credits:
Special thanks to @Freezen for adding this problem and creating all test cases.
*/

/* O(n*k), O(k) */
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (k > static_cast<int>(prices.size()))
            k = static_cast<int>(prices.size());
        if (k <= 0 || prices.size() == 0)
            return 0;

        vector<int> sell(k, 0);
        vector<int> hold(k, numeric_limits<int>::min());

        for (auto price : prices) {
            for (int i=k-1; i > 0; --i) {
                sell[i] = max(sell[i], hold[i] + price);
                hold[i] = max(hold[i], sell[i-1] - price);
            }
            sell[0] = max(sell[0], hold[0] + price);
            hold[0] = max(hold[0], -price);
        }

        return sell[k-1];
    }
};

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (k <= 0 || prices.size() == 0)
            return 0;
        if (k >= static_cast<int>(prices.size()) / 2)
            return quick_solve(prices);

        vector<int> sell(k, 0);
        vector<int> hold(k, numeric_limits<int>::min());

        for (auto price : prices) {
            for (int i=k-1; i > 0; --i) {
                sell[i] = max(sell[i], hold[i] + price);
                hold[i] = max(hold[i], sell[i-1] - price);
            }
            sell[0] = max(sell[0], hold[0] + price);
            hold[0] = max(hold[0], -price);
        }

        return sell[k-1];
    }
private:
    int quick_solve(vector<int>& prices) {
        int ret = 0;
        auto last = prices[0];
        for (auto price : prices) {
            if (price > last)
                ret += price - last;
            last = price;
        }
        return ret;
    }
};

/* O(n + klog(n)), O(n) */
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        auto n = prices.size();
        if (k <= 0 || n == 0)
            return 0;

        auto v = 0;
        auto p = 0;
        priority_queue<int> profs;
        stack<vector<int>> vp_pairs;
        while (p < n-1) {
            // find next valley and peak
            for (v = p; v < n-1 && prices[v] >= prices[v+1]; ++v);
            for (p = v; p < n-1 && prices[p] <= prices[p+1]; ++p);
            while (!vp_pairs.empty() && prices[v] < prices[vp_pairs.top()[0]]) {
                profs.emplace(prices[vp_pairs.top()[1]] - prices[vp_pairs.top()[0]]);
                vp_pairs.pop();
            }

            while (!vp_pairs.empty() && prices[p] > prices[vp_pairs.top()[1]]) {
                profs.emplace(prices[vp_pairs.top()[1]] - prices[v]);
                v = vp_pairs.top()[0];
                vp_pairs.pop();
            }
            vp_pairs.emplace(vector<int>{v,p});
        }

        while (!vp_pairs.empty()) {
            profs.emplace(prices[vp_pairs.top()[1]] - prices[vp_pairs.top()[0]]);
            vp_pairs.pop();
        }

        auto prof = 0;
        while (!profs.empty() && k--) {
            prof += profs.top();
            profs.pop();
        }

        return prof;
    }
};
