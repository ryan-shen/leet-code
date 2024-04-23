#include "../shared/shared.h"
#include <iostream>
#include <math.h>
#include <set>
using namespace std;

/*
  時間複雜度：O(n^2)
*/
class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int maxLength = 0;

    for (int i = 0; i < s.length(); i++) {
      set<char> set;
      int length = 0;

      for (int j = i; j < s.length(); j++) {
        if (set.count(s[j])) {
          length = j - i;
          break;
        }

        if (j == s.length() - 1) {
          length = j - i + 1;
          return max(maxLength, length);
        }

        set.insert(s[j]);
      }

      maxLength = max(maxLength, length);
    }

    return maxLength;
  }
};

int main(int argc, const char* argv[]) {
  Solution* solution = new Solution();
  string s = "pwwkew";

  int result = solution->lengthOfLongestSubstring(s);
  cout << result;

  return 0;
}