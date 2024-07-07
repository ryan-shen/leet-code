#include "../shared/shared.h"
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

/*
  時間複雜度：O(n*n!)
*/
class Solution {
public:
  // 答案
  vector<vector<int>> answer;
  // 塞入答案前被處理的當前這一組排列
  vector<int> currentPermutation;

  vector<vector<int>> permute(vector<int>& nums) {
    solve(nums, 0);
    return answer;
  }

  // 透過 DFS 實作全排列
  void solve(vector<int>& nums, int layer) {
    if (layer == nums.size()) {
      answer.push_back(currentPermutation);
      return;
    }

    for (int i = 0; i < nums.size(); i++) {
      if (contains(currentPermutation, nums[i])) {
        continue;
      }

      currentPermutation.push_back(nums[i]);

      solve(nums, layer + 1);

      currentPermutation.pop_back();
    }
  }

  // 回傳陣列中是否有指定的數字
  bool contains(vector<int>& vec, int num) {
    for (int i = 0; i < vec.size(); i++) {
      if (vec[i] == num) {
        return true;
      }
    }
    return false;
  }
};

int main(int argc, const char* argv[]) {
  Solution* solution = new Solution();
  vector<int> input = {0, 1};

  vector<vector<int>> result = solution->permute(input);
  for (auto i : result) {
    for (auto j : i) {
      cout << j << " ";
    }
    cout << endl;
  }

  return 0;
}