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
  vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> res;

    int start = -1;
    int end = -1;
    bool status = 0;
    for (int i = 0; i < intervals.size(); i++) {
      // 結束插入了
      if (status == 2) {
        res.push_back(intervals[i]);
        continue;
      }

      if (intervals[i][0] <= newInterval[0] && intervals[i][1] >= newInterval[0]) {
        start = intervals[i][0];
        status = 1;
        continue;
      }

      if (intervals[i][0] <= newInterval[1] && intervals[i][1] >= newInterval[1]) {
        end = intervals[i][1];
        status = 2;
        continue;
      }

      res.push_back(intervals[i]);
    }

    return res;
  }
};

int main(int argc, const char* argv[]) {
  Solution* solution = new Solution();
  int input = 1;

  int result = solution->f(input);
  cout << result << endl;

  return 0;
}