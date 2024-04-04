#include <iostream>
#include <string.h>
#include <stack>
using namespace std;

/*
  時間複雜度：O(n)
*/
class Solution {
public:
  bool isValid(string s) {
    stack<char> stack;
    for (size_t i = 0; i < s.length(); i++)
    {
      //遇到閉合括號 ')' 時只要前一個不是 '(' 就算不合法
      if (s[i] == ')') {
        if (stack.empty() || stack.top() != '(') {
          return false;
        }

        stack.pop();
        continue;
      }

      //遇到閉合括號 ']' 時只要前一個不是 '[' 就算不合法
      if (s[i] == ']') {
        if (stack.empty() || stack.top() != '[') {
          return false;
        }

        stack.pop();
        continue;
      }

      //遇到閉合括號 '}' 時只要前一個不是 '{' 就算不合法
      if (s[i] == '}') {
        if (stack.empty() || stack.top() != '{') {
          return false;
        }

        stack.pop();
        continue;
      }

      // 非閉合括號一律直接放入 stack
      stack.push(s[i]);
    }

    return stack.empty();
  }
};