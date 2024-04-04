#include <iostream>
#include <vector>
#include <math.h>
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //將指標指向 Heap 內的節點，以免函式結束時所指向的位址被回收
        ListNode* l3 = new ListNode();
        ListNode* ptr = l3;
        int carry = 0;

        while (true) {
            ptr->val = (l1->val + l2->val + carry) % 10;
            carry = (l1->val + l2->val + carry) / 10;
            l1 = l1->next;
            l2 = l2->next;

            if (l1 == nullptr) {
                while (l2 != nullptr) {
                    ptr->next = new ListNode((l2->val + carry) % 10);
                    carry = (l2->val + carry) / 10;
                    ptr = ptr->next;
                    l2 = l2->next;
                }

                if (carry) {
                    ptr->next = new ListNode(carry);
                }

                return l3;
            }

            if (l2 == nullptr) {
                while (l1 != nullptr) {
                    ptr->next = new ListNode((l1->val + carry) % 10);
                    carry = (l1->val + carry) / 10;
                    ptr = ptr->next;
                    l1 = l1->next;
                }

                if (carry) {
                    ptr->next = new ListNode(carry);
                }

                return l3;
            }

            ptr->next = new ListNode();
            ptr = ptr->next;
        }
    }
};

int main(int argc, const char* argv[])
{
    Solution* solution = new Solution();
    ListNode input12(7);
    ListNode input11(3, &input12);
    ListNode input22(2);
    ListNode input21(9, &input22);

    ListNode* result = solution->addTwoNumbers(&input11, &input21);
    for (auto ptr = result; ptr != nullptr; ptr = ptr->next)
    {
        cout << ptr->val << endl;
    }

    return 0;
}