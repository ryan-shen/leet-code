#include "../shared/shared.h"
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

/*
  時間複雜度：O(n^2)
*/
class Solution {
public:
  string convert(string s, int numRows) {
    // 用一個二維陣列模擬 Zigzag 後的地圖
    char arr[1000][1000] = {};

    // 一開始先將地圖清空
    for (int i = 0; i < numRows; i++) {
      for (int j = 0; j < 1000; j++) {
        arr[i][j] = '\0';
      }
    }

    int i = 0;
    int j = 0;
    // 當前巡覽到的字元索引
    int charIndex = 0;
    // 是否正在進行斜向移動
    bool zigzagging = false;
    while (charIndex < s.length()) {
      arr[i][j] = s[charIndex++];

      if (numRows == 1) {
        j++;
      } else if (i == numRows - 1) {
        i--;
        j++;
        zigzagging = true;
      } else if (i == 0) {
        i++;
        zigzagging = false;
      } else if (zigzagging) {
        i--;
        j++;
      } else {
        i++;
      }
    }

    // 萃取地圖中的字元
    string result = "";
    for (int i = 0; i < numRows; i++) {
      for (int j = 0; j < 1000; j++) {
        if (arr[i][j] != '\0') {
          result.push_back(arr[i][j]);
        }
      }
    }

    return result;
  }
};

int main(int argc, const char* argv[]) {
  Solution* solution = new Solution();
  string s = "PAYPALISHIRING";
  int numRows = 3;

  string result = solution->convert(s, numRows);
  cout << result << endl;

  return 0;
}