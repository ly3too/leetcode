/*
Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2.

Note:

The length of both num1 and num2 is < 110.
Both num1 and num2 contains only DIGITS 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.
*/

#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <sstream>
#include <iomanip>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
      auto num1_v = get_int(num1);
      auto num2_v = get_int(num2);
      auto n1 = num1_v.size();
      auto n2 = num2_v.size();

      vector<int> result(n1+n2, 0);
      int i = 0;
      int j = 0;
      int sum;
      for (auto rit1=num1_v.rbegin(); rit1 != num1_v.rend(); ++rit1) {
          auto x1 = *rit1;
          j = i++;
          int carry=0;
        for (auto rit2=num2_v.rbegin(); rit2 != num2_v.rend(); ++rit2) {
            auto x2 = *rit2;
          sum = x1*x2 + carry + result[j];
          result[j] = sum % MAX;
          carry = sum / MAX;
/* debug */ /*
          cout << "sum= " << sum << endl;
          cout << "MAX= " << MAX << endl;
          cout << "result[j]= " << result[j] << " carry= " << carry << endl;
*/
          ++j;
        }
        result[j] += carry;
      }

      // convert int to string
      i = n1 + n2 - 1;
      while(result[i] == 0 && i>0) {
          --i;
      }

      string output{to_string(result[i--])};
      while (i>=0) {
          output += to_string_zero_pad(result[i--]);
      }

      return output;
    }

private:
    const int DIGITS = 4;
    const int MAX = pow(10, DIGITS);

    vector<int> get_int(string &num) {
      auto N = num.size();
      vector<int> result;
      if (N <= 0) {
        result.push_back(0);
        return result;
      }

      // add padding 0
      int i = static_cast<int>(N%DIGITS);
      while (i % DIGITS) {
          num = "0" + num;
          ++i;
      }

      i = 0;
      int tmp = 0;
      for (auto it = num.begin(); it != num.end(); ++it) {
        ++i;
        tmp = tmp*10 + static_cast<int>(*it - '0');
/* debug */ /*
        cout << "*it= " << *it << endl;
*/
        if (i == DIGITS) {
          result.push_back(tmp);
          tmp = 0;
          i = 0;
        }
      }
      if (i) {
        result.push_back(tmp);
      }
/* debug */ /*
      for (auto x : result) {
          cout << x << " ";
      }
      cout << endl;
*/
      return result;
    }

    string to_string_zero_pad(int num)
    {
        ostringstream ss;
        ss << setw(DIGITS) << setfill( '0' ) << num;
        return ss.str();
    }
};

int main () {
    string n1{"123456"};
    string n2{"1234567"};

    auto output = Solution{}.multiply(n1, n2);

    cout << n1 << endl << " x " << endl << n2 << endl << " = " << endl;
    cout << output << endl;

    return 0;
}
