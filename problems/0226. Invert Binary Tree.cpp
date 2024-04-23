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
  TreeNode* invertTree(TreeNode* root) {
    if (root == nullptr) {
      return root;
    }

    TreeNode* leftNode = root->left;
    TreeNode* rightNode = root->right;

    // 遞迴搜尋子節點
    invertTree(leftNode);
    invertTree(rightNode);

    // 做交換，因為沒有子節點等於指向 nullptr，所以不用管有沒有子節點
    root->left = rightNode;
    root->right = leftNode;

    return root;
  }
};

void print(TreeNode* currentNode) {
  if (currentNode == nullptr) {
    return;
  }

  cout << currentNode->val << ' ';

  TreeNode* leftNode = currentNode->left;
  TreeNode* rightNode = currentNode->right;

  print(leftNode);
  print(rightNode);
}

int main(int argc, const char* argv[]) {
  Solution* solution = new Solution();
  TreeNode* root = vectorToTree({4, 2, 7, 1, 3, 6, 9});

  TreeNode* result = solution->invertTree(root);
  print(root);

  return 0;
}
