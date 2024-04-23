#include "../shared/shared.h"
#include <algorithm>
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
  vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> res;
    int i = 0;

    // 複製與新區間左側不重疊的部分
    for (; i < intervals.size() && intervals[i][1] < newInterval[0]; i++) {
      res.push_back(intervals[i]);
    }

    // 找出重疊部分的最小與最大值，找到後推入此值當合併後的結果
    int overlapMin = newInterval[0];
    int overlapMax = newInterval[1];
    for (; i < intervals.size() && intervals[i][0] <= newInterval[1]; i++) {
      overlapMin = min(overlapMin, intervals[i][0]);
      overlapMax = max(overlapMax, intervals[i][1]);
    }
    res.push_back({overlapMin, overlapMax});

    // 複製與新區間右側不重疊的部分
    for (; i < intervals.size() && intervals[i][0] > newInterval[1]; i++) {
      res.push_back(intervals[i]);
    }

    return res;
  }
};

int main(int argc, const char* argv[]) {
  Solution* solution = new Solution();
  vector<vector<int>> intervals = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
  vector<int> newInterval = {4, 8};

  vector<vector<int>> result = solution->insert(intervals, newInterval);
  for (auto vec : result) {
    cout << "[" << vec[0] << "," << vec[1] << "] ";
  }

  return 0;
}