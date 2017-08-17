/*
Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.
*/
class Solution {
public:
    string intToRoman(int num) {
        const vector<int> nums{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        const vector<string> romans{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        string res;

        for (int i=0; i<nums.size(); ++i) {
            while (num >= nums[i]) {
                num -= nums[i];
                res += romans[i];
            }
        }

        return res;
    }
};
