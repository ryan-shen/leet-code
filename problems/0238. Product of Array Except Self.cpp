#include "../shared/shared.h"
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

/*
  時間複雜度：O(n)
  空間複雜度：O(n)
*/
class Solution {
public:
  vector<int> productExceptSelf(vector<int>& nums) {
    int length = nums.size();
    vector<int> answer(length, 1);

    // 從第一個元素開始的乘積
    int leftProduct = 1;
    // 此迴圈做完後每個元素都會擁有其左邊所有元素的乘積
    for (int i = 1; i < length; i++) {
      leftProduct *= nums[i - 1];
      answer[i] *= leftProduct;
    }

    // 從最後一個元素開始的乘積
    int rightProduct = 1;
    // 此迴圈做完後每個元素都會擁有其右邊所有元素的乘積
    for (int i = length - 2; i >= 0; i--) {
      rightProduct *= nums[i + 1];
      answer[i] *= rightProduct;
    }

    return answer;
  }
};

int main(int argc, const char* argv[]) {
  Solution* solution = new Solution();
  vector<int> nums = {-1, 1, 0, -3, 3};

  vector<int> result = solution->productExceptSelf(nums);
  for (auto i : result) {
    cout << i << endl;
  }

  return 0;
}