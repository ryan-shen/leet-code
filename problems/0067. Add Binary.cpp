#include "../shared/shared.h"
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

/*
  時間複雜度：O(n)
*/
class Solution {
public:
  string addBinary(string a, string b) {
    //確保 a 大於等於 b
    if (a.length() < b.length()) {
      swap(a, b);
    }

    //從低位到高位記錄加總後的位元值
    vector<char> vec;
    int carry = 0;
    for (int i = a.length() - 1, j = b.length() - 1; i >= 0; i--, j--) {
      int aDigit = (int)a[i] - 48;
      int bDigit = j >= 0 ? (int)b[j] - 48 : 0;
      int sum = aDigit + bDigit + carry;
      carry = sum / 2;
      sum %= 2;
      vec.push_back((char)(sum + 48));
    }
    if (carry) {
      vec.push_back('1');
    }

    //反向印出字串
    string s(vec.rbegin(), vec.rend());
    return s;
  }
};

int main(int argc, const char* argv[]) {
  Solution* solution = new Solution();
  string a = "1";
  string b = "11";

  string result = solution->addBinary(a, b);
  cout << result << endl;

  return 0;
}