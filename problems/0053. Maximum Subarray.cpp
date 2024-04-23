#include "../shared/shared.h"
#include <climits>
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

/*
  時間複雜度：O(n)
  空間複雜度：O(1)
*/
class Solution {
public:
  int maxSubArray(vector<int>& nums) {
    // 使用 Kadane's Algorithm
    int maxSum = nums[0];
    int maxEndingHere = nums[0];

    // 巡覽道每個元素時都去比對「當前元素」與「當前元素 +（該區段）加總到上一個元素時的最大值」
    // 並取較大的那一方當作「加總到此元素時的最大值」
    for (int i = 1; i < nums.size(); i++) {
      maxEndingHere = max(nums[i], maxEndingHere + nums[i]);
      maxSum = max(maxSum, maxEndingHere);
    }

    return maxSum;
  }

  // 方法二，算是 Kadane's Algorithm 的變種，也是使用動態規劃
  int maxSubArray2(vector<int>& nums) {
    // 表示到目前為止的所有區段中總和最大的那個區段的總和
    int maxSum = nums[0];

    // 從 Index 0 開始逐筆更新陣列內的元素，每個元素所代表的意思為「從區段開始加到現在這個 Index 時的總和」
    // 當此值為負數時代表這是一個區段的結束，因為下一個 Index 拿這個值去加也沒有意義
    for (int i = 1; i < nums.size(); i++) {
      nums[i] = max(nums[i], nums[i - 1] + nums[i]);
      maxSum = max(maxSum, nums[i]);
    }

    return maxSum;
  }
};

int main(int argc, const char* argv[]) {
  Solution* solution = new Solution();
  vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

  int result = solution->maxSubArray2(nums);
  cout << result << endl;

  return 0;
}