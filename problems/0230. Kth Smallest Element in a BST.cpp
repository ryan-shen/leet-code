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
  //使用中序遍歷所巡覽出來的順序就是從小到大，因此只要計算到第 k 個節點即可
  int currentIndex = 0;
  int kthSmallest(TreeNode* root, int k) {
    // 回傳 -1 表示該節點是 nullptr 或是該子樹的節點數量不到 k
    if (root == nullptr) {
      return -1;
    }

    // 如果回傳值非 -1 代表找到答案，直接回傳
    int left = kthSmallest(root->left, k);
    if (left != -1) {
      return left;
    }

    currentIndex++;
    if (currentIndex == k) {
      return root->val;
    }

    // 因為巡覽右節點之後沒有事情要做了，所以直接回傳右節點傳回來的值
    return kthSmallest(root->right, k);
  }
};

int main(int argc, const char* argv[]) {
  Solution* solution = new Solution();
  TreeNode* node = vectorToTree({3, 1, 4, 0, 2});

  int result = solution->kthSmallest(node, 2);
  cout << result << endl;

  return 0;
}