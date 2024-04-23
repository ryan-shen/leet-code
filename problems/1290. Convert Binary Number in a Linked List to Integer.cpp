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
  int getDecimalValue(ListNode* head) {
    //從大位到小位巡覽，每次都先乘 2 再加上該位數的值
    int sum = 0;
    while (head != nullptr) {
      sum = (sum << 1) + head->val;
      head = head->next;
    }

    return sum;
  }
};

int main(int argc, const char* argv[]) {
  Solution* solution = new Solution();
  ListNode* head = vectorToList({1, 0, 1});

  int result = solution->getDecimalValue(head);
  cout << result << endl;

  return 0;
}