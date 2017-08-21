/*
Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

For example,

Given numerator = 1, denominator = 2, return "0.5".
Given numerator = 2, denominator = 1, return "2".
Given numerator = 2, denominator = 3, return "0.(6)".
*/

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        bool sign = ((numerator^denominator) < 0);

        auto dvdn = llabs(numerator);
        auto dvdr = llabs(denominator);

        string res;
        if (sign && numerator != 0)
            res = '-';

        res += to_string(dvdn / dvdr);

        if (dvdn % dvdr) {
            res += string{'.'} + decimal(dvdn, dvdr);
        }

        return res;
    }
private:

    /* denominator must bigger than numerator */
    string decimal(long long numerator, long long denominator) {
        unordered_map<long long, int> map;
        string res;
        numerator = numerator % denominator;

        for (int indx=0; (numerator%denominator) != 0; ++indx, numerator %= denominator) {
            numerator *= 10;
            if (map.find(numerator) != map.end()) {
                return res.substr(0,map[numerator]) + '(' + res.substr(map[numerator]) + ')';
            }

            auto digit = numerator / denominator;
            res += to_string(digit);
            map[numerator] = indx;
        }

        return res;
    }
};
