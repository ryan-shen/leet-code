#include "../shared/shared.h"
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
using namespace std;

/*
  解法：Dynamic Programming
  時間複雜度：O(n^2)
  空間複雜度：O(n^2)
*/
class Solution {
public:
  string longestPalindrome(string s) {
    int length = s.length();
    vector<vector<bool>> isPalindrome;
    int start = 0;
    int end = 0;

    /*
        建立一張 DP 表，只會用到左下三角形（不能使用右上，因為在巡覽到 dp[0][n-1] 時 dp[1][n-2]
       的值還沒確定，使用遞迴去填的話提交時會 MLE） 這張 DP 表如下 0   1   2 0   F 1   F   F 2   F   F   F
    */
    for (int i = 0; i < length; i++) {
      isPalindrome.push_back(vector<bool>());
      for (int j = 0; j <= i; j++) {
        isPalindrome[i].push_back(false);
      }
    }

    /*
        對每個組合進行檢驗，如果滿足以下兩個條件，那麽 s[i ~ j] 就是個回文字串
        1. s[i] 等於 s[j]
        2. i 跟 j 相等或相鄰，或是 s[(i + 1) ~ (j - 1)] 也是個回文字串
    */
    for (int i = 0; i < length; i++) {
      isPalindrome[i][i] = 1;
      for (int j = 0; j < i; j++) {
        if (s[i] == s[j] && (i - j == 1 || isPalindrome[i - 1][j + 1])) {
          isPalindrome[i][j] = true;
          if (i - j > end - start) {
            start = j;
            end = i;
          }
        }
      }
    }

    return string(s.begin() + start, s.begin() + end + 1);
  }
};

/*
  解法：Expand Around Center
  時間複雜度：O(n^2)
  空間複雜度：O(1)
*/
class Solution2 {
public:
  string longestPalindrome(string s) { return s; }
};

/*
  解法：Manacher's Algorithm
  時間複雜度：O(n)
  空間複雜度：O(n)
*/
class Solution3 {
public:
  string longestPalindrome(string s) { return s; }
};

int main(int argc, const char* argv[]) {
  Solution* solution = new Solution();
  string input = "abcbad";

  string result = solution->longestPalindrome(input);
  cout << result << endl;

  return 0;
}