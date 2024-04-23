#include "../shared/shared.h"
#include <iostream>
#include <stack>
#include <string.h>
using namespace std;

/*
  時間複雜度：O(n)
*/
class Solution {
public:
  bool isPalindrome(string s) {
    // 為了效能因此不重新組出只含有合法字元的字串，這樣可讓時間複雜度從 2n 降為 n
    int startIndex = 0;
    int endIndex = s.length() - 1;

    while (startIndex < endIndex) {
      char startChar = s[startIndex];
      char endChar = s[endIndex];

      // 跳過非法字元
      if (!(startChar >= '0' && startChar <= '9' || startChar >= 'A' && startChar <= 'Z' ||
            startChar >= 'a' && startChar <= 'z')) {
        startIndex++;
        continue;
      }

      if (!(endChar >= '0' && endChar <= '9' || endChar >= 'A' && endChar <= 'Z' || endChar >= 'a' && endChar <= 'z')) {
        endIndex--;
        continue;
      }

      // 轉為小寫字元後再做比對
      char lowerStartChar = startChar >= 'A' && startChar <= 'Z' ? startChar + 'z' - 'Z' : startChar;
      char lowerEndChar = endChar >= 'A' && endChar <= 'Z' ? endChar + 'z' - 'Z' : endChar;
      if (lowerStartChar != lowerEndChar) {
        return false;
      }

      startIndex++;
      endIndex--;
    }

    return true;
  }
};

int main(int argc, const char* argv[]) {
  Solution* solution = new Solution();

  bool result = solution->isPalindrome("a++");
  cout << result;

  return 0;
}