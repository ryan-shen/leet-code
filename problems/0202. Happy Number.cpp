#include "../shared/shared.h"
#include <iostream>
#include <math.h>
#include <unordered_map>
#include <vector>
using namespace std;

/*
  時間複雜度：O(logn)
*/
class Solution {
public:
  bool isHappy(int n) {
    // 用來計算 Happy Number 的演算法最終一定會出現循環，因為每個位數的平方加總的最大值是有限的（以本題測資最大值來說是
    // (1^2 + (9^2)*9) = 730）

    // 用一個 map 來記錄之前出現過的 sum
    unordered_map<int, bool> map;

    while (n != 1) {
      int sum = 0;

      // 把每個位數的平方做加總
      while (n > 0) {
        sum += pow(n % 10, 2);
        n /= 10;
      }

      if (map.contains(sum)) {
        return false;
      }

      map[sum] = true;
      n = sum;
    }

    return true;
  }
};

int main(int argc, const char* argv[]) {
  Solution* solution = new Solution();
  int input = 19;

  int result = solution->isHappy(input);
  cout << result << endl;

  return 0;
}