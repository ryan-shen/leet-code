#include "../shared/shared.h"
#include <iostream>
#include <math.h>
#include <queue>
#include <vector>
using namespace std;

/*
  時間複雜度：O(logn)
*/
class Solution {
public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    while (root != nullptr) {
      // 如果 p 跟 q 都小於根的話，根就往左移動
      if (root->val > p->val && root->val > q->val) {
        root = root->left;
      }
      // 如果 p 跟 q 都小於根的話，根就往右移動
      else if (root->val < p->val && root->val < q->val) {
        root = root->right;
      }
      // 表示根的值介於 p 跟 q 之間，必定為最低共同祖先（要不然這就不是一棵二元搜尋樹了）
      else {
        break;
      }
    }

    return root;
  }
};

int main(int argc, const char* argv[]) {
  Solution* solution = new Solution();
  TreeNode* root = vectorToTree({6, 2, 8, 0, 4, 7, 9, 3, 5});

  TreeNode* result = solution->lowestCommonAncestor(root, new TreeNode(2), new TreeNode(4));
  cout << root->val << endl;

  return 0;
}