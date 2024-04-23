#include "../shared/shared.h"
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

/*
  時間複雜度：O(logn)
*/
class Solution {
public:
  int search(vector<int>& nums, int target) {
    int startIndex = 0;
    int endIndex = nums.size() - 1;

    while (startIndex <= endIndex) {
      int middleIndex = (startIndex + endIndex) / 2;
      int middleNum = nums[middleIndex];

      if (middleNum < target) {
        startIndex = middleIndex + 1;
        continue;
      }

      if (middleNum > target) {
        endIndex = middleIndex - 1;
        continue;
      }

      return middleIndex;
    }

    return -1;
  }
};

int main(int argc, const char* argv[]) {
  Solution* solution = new Solution();
  vector<int> nums = {1, 2, 3, 4, 5};
  int target = 6;

  int result = solution->search(nums, target);
  cout << result << endl;

  return 0;
}