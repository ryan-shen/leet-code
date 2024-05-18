#include "../shared/shared.h"
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

/*
  時間複雜度：O(1)
  空間複雜度：O(1)
*/
class Solution {
public:
  int numWaterBottles(int numBottles, int numExchange) {
    // 總共喝到的水瓶數
    int total = 0;
    // 目前持有空瓶數
    int emptyBottles = 0;

    while (numBottles) {
      total += numBottles;

      // 暫存目前持有滿瓶數，以免下一行的 emptyBottles 受到影響
      int fullBottles = (numBottles + emptyBottles) / numExchange;
      emptyBottles = (numBottles + emptyBottles) % numExchange;

      numBottles = fullBottles;
    }

    return total;
  }
};

int main(int argc, const char* argv[]) {
  Solution* solution = new Solution();

  int result = solution->numWaterBottles(15, 8);
  cout << result << endl;

  return 0;
}