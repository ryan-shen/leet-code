#include "../shared/shared.h"
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
  bool isSymmetric(TreeNode* root) {
    // 透過Top-Down的方式依照對稱性分裂成左右兩邊，並看兩邊節點是否同值，同值的話再依照對稱性遞迴往下檢查是否符合對稱性
    // 本題也可透過分別從左邊與右邊使用前序走訪，之後看走出來的結果是否相同來看是否對稱
    return isSymmetric(root->left, root->right);
  }

  bool isSymmetric(TreeNode* leftNode, TreeNode* rightNode) {
    return leftNode == nullptr && rightNode == nullptr ||
           leftNode != nullptr && rightNode != nullptr && leftNode->val == rightNode->val &&
               isSymmetric(leftNode->left, rightNode->right) && isSymmetric(leftNode->right, rightNode->left);
  }
};

int main(int argc, const char* argv[]) {
  Solution* solution = new Solution();
  TreeNode* root = vectorToTree({4, 2, 2, 1, 3, 3, 1});

  bool result = solution->isSymmetric(root);
  cout << result << endl;

  return 0;
}