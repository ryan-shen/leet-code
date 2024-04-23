#include "../shared/shared.h"
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

/*
  時間複雜度：O(1)
*/
class Solution {
public:
  int fib[46];

  Solution() {
    fib[1] = 1;
    fib[2] = 2;
    for (int i = 3; i <= 45; i++) {
      fib[i] = fib[i - 1] + fib[i - 2];
    }
  }

  int climbStairs(int n) {
    return fib[n];

    //也可考慮使用通式
    // n = n + 1;
    // return pow(5, 0.5) / 5 * (pow((1 + pow(5, 0.5)) / 2, n) - pow((1 - pow(5, 0.5)) / 2, n));
  }
};

int main(int argc, const char* argv[]) {
  Solution* solution = new Solution();
  int input = 45;

  int result = solution->climbStairs(input);
  cout << result << endl;

  return 0;
}