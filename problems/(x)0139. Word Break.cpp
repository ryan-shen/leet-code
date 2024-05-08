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
  bool pass = false;

  bool wordBreak(string s, vector<string>& wordDict) {
    solve(s, wordDict, 0);
    return pass;
  }

  void solve(string s, vector<string>& wordDict, int pos) {
    if (pass) {
      return;
    }

    for (int i = 0; i < wordDict.size(); i++) {
      if (contains(s, wordDict[i], pos)) {
        if (wordDict[i].length() + pos == s.length()) {
          pass = true;
          return;
        }

        solve(s, wordDict, pos + wordDict[i].length());

        if (pass) {
          return;
        }
      }
    }
  }

  bool contains(string s, string word, int pos) {
    if (word.length() + pos > s.length()) {
      return false;
    }

    for (int i = 0; i < word.length(); i++) {
      if (s[pos + i] != word[i]) {
        return false;
      }
    }

    return true;
  }
};

int main(int argc, const char* argv[]) {
  Solution* solution = new Solution();
  string s = "leetcode";
  vector<string> wordDict = {"leet", "code"};

  int result = solution->wordBreak(s, wordDict);
  cout << result << endl;

  return 0;
}