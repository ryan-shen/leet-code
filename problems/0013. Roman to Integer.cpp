#include "../shared/shared.h"
#include <iostream>
#include <math.h>
#include <unordered_map>
using namespace std;

/*
  時間複雜度：O(n)
*/
class Solution {
public:
  unordered_map<char, int> map = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

  int romanToInt(string s) {
    int sum = 0;
    for (int i = 0; i < s.length(); i++) {
      //每個位數都加上其代表的數值
      int value = map[s[i]];

      //因為是由大到小排列，所以如果當下一個字元比這個字元還大（例如表示 4、9 的時候），則第一個字元要用減的
      if (s[i + 1] != '\0' && map[s[i]] < map[s[i + 1]]) {
        value *= -1;
      }

      sum += value;
    }

    return sum;
  }
};

int main(int argc, const char* argv[]) {
  Solution* solution = new Solution();
  string input = "MCMXCIV";

  int result = solution->romanToInt(input);
  cout << result << endl;

  return 0;
}