/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/
/* O(n), O(1) */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int hold1 = numeric_limits<int>::min(); // max prof if we buy first stock
        int hold2 = numeric_limits<int>::min(); // max prof if we buy second
        int sell1 = 0; // max prof if we sell 1st;
        int sell2 = 0; // max prof if we sell 2nd;
        for (auto price : prices) {
            sell2 = max(sell2, hold2 + price);
            hold2 = max(hold2, sell1 - price);
            sell1 = max(sell1, price + hold1);
            hold1 = max(hold1, -price);
        }

        return sell2;
    }
};
