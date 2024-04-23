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
  int firstMissingPositive(vector<int>& nums) {
    // 目標：將每個數字放在與其值相同的 index 上，最後從 index = 1 開始檢查，只要檢查到 index != num
    // 的就表示該數字沒出現在 nums 裡
    int length = nums.size();

    // 為了可讀性因此在最前面墊一個垃圾元素，如此一來每個數字所該在的 index 就會剛好是 num 而非 num - 1
    nums.insert(nums.begin(), -1);

    // 從 index = 1 開始逐一替換元素到正確的位置
    for (size_t i = 1; i <= length; i++) {
      // 只要換過來的數字還在 nums 的長度內就表示該數字還可以被放在另一個位置
      // 此 while 在這支程式裡最多只會跑 n 次（因為每個位置只會被安插一次數字），因此時間複雜度最多只會是 2n 而非 n^2
      // nums[i] != nums[nums[i]] 用來避免像 [1, 1] 這種無窮替換的情境
      while (nums[i] > 0 && nums[i] <= length && nums[i] != i && nums[i] != nums[nums[i]]) {
        swap(nums[i], nums[nums[i]]);
      }
    }

    // 從 index = 1 開始找沒有出現在 nums 裡的數字即是答案
    for (size_t i = 1; i <= length; i++) {
      if (nums[i] != i) {
        return i;
      }
    }

    // 當陣列裡面元素剛好是 1 ~ n，那最小沒出現過的正整數就是陣列大小 + 1
    return length + 1;
  }
};

int main(int argc, const char* argv[]) {
  Solution* solution = new Solution();
  vector<int> vec = {1, 1};

  int result = solution->firstMissingPositive(vec);
  cout << result << endl;

  return 0;
}