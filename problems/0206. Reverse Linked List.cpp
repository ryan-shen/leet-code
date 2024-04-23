#include "../shared/shared.h"
#include <cstddef>
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

/*
  時間複雜度：O(n)
  空間複雜度：O(1)
*/
class Solution {
public:
  ListNode* reverseList(ListNode* head) {
    // 從頭走到尾，沿途事先記錄每個節點的上一個節點與原本下一個節點的所在位址，之後讓每個節點都改成指向其上一個節點
    ListNode* currentNode = head;
    ListNode* nextNode;
    ListNode* previousNode = nullptr;

    while (currentNode != nullptr) {
      nextNode = currentNode->next;
      currentNode->next = previousNode;

      previousNode = currentNode;
      currentNode = nextNode;
    }

    return previousNode;
  }
};

int main(int argc, const char* argv[]) {
  Solution* solution = new Solution();
  ListNode* input = vectorToList({1, 2, 3, 4});

  ListNode* result = solution->reverseList(input);
  cout << result->val << endl;

  return 0;
}