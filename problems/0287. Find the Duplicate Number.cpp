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
  int findDuplicate(vector<int>& nums) {
    // 因為不能影響到原陣列，且不能因為數字變多而消耗更多空間，因此此題必須使用 Floyd 判圈算法
    // 將原本的鏈結串列轉為圖形，每個 index 上的值即表示下一個指向的 index

    // slow 從起點開始每次走一步，fast 從交會點開始每次走兩步，最終相遇的位置就是交會點
    int slow = nums[0];
    int fast = nums[0];

    // 因為題目說一定會有重複的數字，所以可以保證 slow 與 fast 最終一定會相遇
    do {
      slow = nums[slow];
      fast = nums[nums[fast]];
    } while (slow != fast);

    // slow 從起點開始每次走一步，fast 從交會點開始每次走一步，最終相遇的位置就是環的起點
    slow = nums[0];

    while (slow != fast) {
      slow = nums[slow];
      fast = nums[fast];
    }

    return slow;
  }
};

int main(int argc, const char* argv[]) {
  Solution* solution = new Solution();
  vector<int> nums = {3, 1, 3, 2};

  int result = solution->findDuplicate(nums);
  cout << result << endl;

  return 0;
}