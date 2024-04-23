#include "shared.h"
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

ListNode* vectorToList(vector<int> vec) {
  if (vec.empty()) {
    return nullptr;
  }

  ListNode* head;
  ListNode* currentNode = head;
  for (int i = 1; i < vec.size(); i++) {
    currentNode->next = new ListNode(vec[i]);
    currentNode = currentNode->next;
  }

  return head;
}

void printList(ListNode* head) {
  while (head != nullptr) {
    cout << head->val << ' ';
    head = head->next;
  }
  cout << endl;
}
