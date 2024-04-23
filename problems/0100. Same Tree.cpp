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
  bool isSameTree(TreeNode* p, TreeNode* q) {
    // 使用前序走訪針對每個節點做以下兩項檢查後若通過，則繼續檢查其左右子節點，否則就算不相等
    // 1. 當前節點不存在（表示從葉子節點指進來的）
    // 2. 兩方都有值且兩個值相等
    return p == nullptr && q == nullptr || p != nullptr && q != nullptr && p->val == q->val &&
                                               isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
  }
};

int main(int argc, const char* argv[]) {
  Solution* solution = new Solution();
  TreeNode* p = vectorToTree({4, 2, 7, 1, 3, 6, 9});
  TreeNode* q = vectorToTree({4, 2, 7, 1, 3, 6, 9});

  bool result = solution->isSameTree(p, q);
  cout << result << endl;

  return 0;
}