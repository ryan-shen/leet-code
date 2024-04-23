#include "../shared/shared.h"
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
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;

    // 從最後面一個一個往前填數字
    while (j >= 0) {
      nums1[k--] = (i >= 0 && nums1[i] > nums2[j]) ? nums1[i--] : nums2[j--];
    }
  }
};

int main(int argc, const char* argv[]) {
  Solution* solution = new Solution();
  vector<int> nums1 = {1, 2, 3, 0, 0, 0};
  vector<int> nums2 = {2, 5, 6};

  solution->merge(nums1, 6, nums2, 3);
  for (int n : nums1) {
    cout << n << ' ';
  }

  return 0;
}