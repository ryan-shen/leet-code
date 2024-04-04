#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

/*
  時間複雜度：O(n)
*/
class Solution {
public:
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* list3 = new ListNode();
    ListNode* head3 = list3;

    // 只要 list1 跟 list2 都還有值就要比大小
    while (list1 != nullptr && list2 != nullptr) {
      // 比較 list1 跟 list2 當前值的大小，並將小的值串到 list3
      if (list1->val <= list2->val) {
        list3->next = list1;
        list3 = list3->next;
        list1 = list1->next;
      }
      else {
        list3->next = list2;
        list3 = list3->next;
        list2 = list2->next;
      }
    }

    // list2 取完值了，將 list1 剩下的值串到 list3
    if (list1 != nullptr) {
      list3->next = list1;
    }
    // list1 取完值了，將 list2 剩下的值串到 list3
    else {
      list3->next = list2;
    }

    // 因為一開始先初始化了一個空的節點方便統一處理巡覽邏輯，所以是回傳 head 的下一個
    return head3->next;
  }
};

int main(int argc, const char* argv[])
{
  Solution* solution = new Solution();
  vector<int> vec1 = { 1,2,3 };
  vector<int> vec2 = { 4 };

  ListNode* list1 = new ListNode();
  ListNode* head1 = list1;
  for (int i = 0; i < vec1.size(); i++)
  {
    list1->next = new ListNode(vec1[i]);
    list1 = list1->next;
  }

  ListNode* list2 = new ListNode();
  ListNode* head2 = list2;
  for (int i = 0; i < vec2.size(); i++)
  {
    list2->next = new ListNode(vec2[i]);
    list2 = list2->next;
  }

  ListNode* result = solution->mergeTwoLists(head1->next, head2->next);
  while (result != nullptr) {
    cout << result->val << " ";
    result = result->next;
  }

  return 0;
}