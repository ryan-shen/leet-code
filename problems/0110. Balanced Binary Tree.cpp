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
  // 取得左右子樹中深度較大的那個值
  int getMaxDepth(TreeNode* root, bool& result) {
    // 表示從葉子呼叫進來的，或是已經找到解答了，就直接當深度 0
    if (root == nullptr || !result) {
      return 0;
    }

    int leftMaxDepth = getMaxDepth(root->left, result);
    int rightMaxDepth = getMaxDepth(root->right, result);

    // 左右子樹深度相差超過 1 就表示不是平衡樹
    if (abs(leftMaxDepth - rightMaxDepth) > 1) {
      result = false;
    }

    // 要算上自己本身這個節點，所以要 + 1
    return max(leftMaxDepth, rightMaxDepth) + 1;
  }

  bool isBalanced(TreeNode* root) {
    // result 表示此樹是否為平衡樹，在遞迴的過程中會共用此變數位址
    bool result = true;
    getMaxDepth(root, result);
    return result;
  }
};

int main(int argc, const char* argv[]) {
  Solution* solution = new Solution();
  TreeNode* input = vectorToTree({1, 2, 2, 3, 4, 3, 4});

  int result = solution->isBalanced(input);
  cout << result << endl;

  return 0;
}