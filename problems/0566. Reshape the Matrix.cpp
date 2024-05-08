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
  vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
    int rowCount = mat.size();
    int columnCount = mat[0].size();
    int total = rowCount * columnCount;

    // 如果沒辦法把所有元素轉換到新矩陣就直接回傳舊矩陣
    if (r * c != total) {
      return mat;
    }

    // 事先配置一個 r * c 的矩陣（初始值為 0）用來存放答案
    vector<vector<int>> result(r, vector<int>(c));

    // 把值逐個從舊矩陣搬到新矩陣（i / 欄數可以得到當前所在的「列」，i % 欄數可以得到當前所在的「欄」）
    for (int i = 0; i < total; i++) {
      result[i / c][i % c] = mat[i / columnCount][i % columnCount];
    }

    return result;
  }
};

int main(int argc, const char* argv[]) {
  Solution* solution = new Solution();
  vector<vector<int>> mat = {{1, 2}, {3, 4}};
  int r = 1;
  int c = 4;

  vector<vector<int>> result = solution->matrixReshape(mat, r, c);
  for (auto vec : result) {
    for (auto n : vec) {
      cout << n << " ";
    }
    cout << endl;
  }

  return 0;
}