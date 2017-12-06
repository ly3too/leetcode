/*
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
*/

/* O(1), O(1) */
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        if (s.size() < 4 || s.size() > 12)
            return {};
        res.clear();

        restoreIpAddresses_recur(s, "", 0, 0);
        return res;
    }
private:
    vector<string> res;

    void restoreIpAddresses_recur(string &s, string &&tmp_res, int idx, int dots) {
        if (idx == s.size() && dots == 4) {
            res.emplace_back(move(tmp_res));
            return;
        }

        if (dots >= 4)
            return;

        for (int i=1; i<=3; ++i) {
            if (idx + i > s.size())
                break;
            auto subs = s.substr(idx, i);
            auto num = stoi(subs);

            if (num > 255 || num < 0)
                break;

            if (dots == 3)
                restoreIpAddresses_recur(s, tmp_res + subs, idx+i, dots+1);
            else
                restoreIpAddresses_recur(s, tmp_res + subs + ".", idx+i, dots+1);

            if (subs[0] == '0')
                break;
        }

    }
};
