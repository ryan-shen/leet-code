#include "../shared/shared.h"
#include <iostream>
#include <math.h>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

/*
  時間複雜度：O(n*n!)
*/
class Solution {
public:
  // 答案
  vector<vector<int>> answer;
  // 用來做答案的去重
  set<string> answerSet;

  // 塞入答案前被處理的當前這一組排列的「值」
  vector<int> currentPermutation;
  // 塞入答案前被處理的當前這一組排列的「索引」
  vector<int> currentIndexPath;

  vector<vector<int>> permuteUnique(vector<int>& nums) {
    solve(nums, 0);
    return answer;
  }

  // 透過 DFS 實作全排列
  void solve(vector<int>& nums, int layer) {
    if (layer == nums.size()) {
      // 如果要塞入的排列已在集合裡面就代表重複
      string currentPermutationString = string(currentPermutation.begin(), currentPermutation.end());
      if (answerSet.contains(currentPermutationString)) {
        return;
      }

      answer.push_back(currentPermutation);
      answerSet.insert(currentPermutationString);
      return;
    }

    for (int i = 0; i < nums.size(); i++) {
      if (contains(currentIndexPath, i)) {
        continue;
      }

      currentPermutation.push_back(nums[i]);
      currentIndexPath.push_back(i);

      solve(nums, layer + 1);

      currentPermutation.pop_back();
      currentIndexPath.pop_back();
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
  vector<int> input = {1, 1, 2};

  vector<vector<int>> result = solution->permuteUnique(input);
  for (auto i : result) {
    for (auto j : i) {
      cout << j << " ";
    }
    cout << endl;
  }

  return 0;
}