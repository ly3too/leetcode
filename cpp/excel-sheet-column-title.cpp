/*
Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB
*/


class Solution {
public:
    string convertToTitle(int n) {
        if (n<=0)
            throw invalid_argument{"n less than 1"};

        string res;
        do {
            --n;
            char ch = 'A' + static_cast<char>(n%26);
            res = ch + res;
            n /= 26;
        } while(n);

        return res;
    }
};
