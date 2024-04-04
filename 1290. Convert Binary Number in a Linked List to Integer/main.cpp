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

int main(int argc, const char* argv[])
{
    Solution* solution = new Solution();
    ListNode node1 = {};
    ListNode node2 = {};
    ListNode node3 = {};
    node1.val = 1;
    node2.val = 0;
    node3.val = 1;
    node1.next = &node2;
    node2.next = &node3;

    int result = solution->getDecimalValue(&node1);
    cout << result << endl;

    return 0;
}