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
  int numTrees(int n) {
    // 解答為卡塔蘭數，公式為 (2n)! / (n! * (n+1)!)
    // 因為直接計算 19! 會爆掉因此要做特殊處理
    long result = 1;

    // 把公式簡化成 (2n * ... n + 2) / n!
    int numeratorStart = n + 2;
    int numeratorEnd = 2 * n;
    int denominatorStart = 2;
    while (numeratorStart <= numeratorEnd || denominatorStart <= n) {
      result *= numeratorStart++;

      // 隨時監控能否有能被分母整除的部分，可以的話就先除把數字縮小
      while (result % denominatorStart == 0 && denominatorStart <= n) {
        result /= denominatorStart++;
      }
    }

    return result;
  }
};

int main(int argc, const char* argv[]) {
  Solution* solution = new Solution();
  int input = 19;

  int result = solution->numTrees(input);
  cout << result << endl;

  return 0;
}