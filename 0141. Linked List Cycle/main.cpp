#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode* node) : val(x), next(node) {}
};

/*
  時間複雜度：O(n)
  空間複雜度：O(1)
*/
class Solution {
public:
    bool hasCycle(ListNode* head) {
        // 沒有節點或只有一個節點表示一定沒有環
        if (head == nullptr || head->next == nullptr) {
            return false;
        }

        // 使用 Floyd 判圈算法
        ListNode* slow = head;
        ListNode* fast = head;

        // 因為 slow 跟 head 初始位址一樣所以要使用 do-while
        do {
            // 當 fast 走到終點都還沒遇到 slow 就代表沒有環
            if (fast->next == nullptr || fast->next->next == nullptr) {
                return false;
            }

            slow = slow->next;
            fast = fast->next->next;
        } while (slow != fast);

        return true;
    }
};

int main(int argc, const char* argv[])
{
    Solution* solution = new Solution();
    ListNode* input = new ListNode(3, new ListNode(2, new ListNode(0, new ListNode(-4))));

    int result = solution->hasCycle(input);
    cout << result << endl;

    return 0;
}