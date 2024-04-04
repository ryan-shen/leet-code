#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

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

int main(int argc, const char* argv[])
{
    Solution* solution = new Solution();
    TreeNode* root = new TreeNode(6,
        new TreeNode(2,
            new TreeNode(0),
            new TreeNode(4,
                new TreeNode(3),
                new TreeNode(5)
            )
        ),
        new TreeNode(8,
            new TreeNode(7),
            new TreeNode(9)
        )
    );

    TreeNode* result = solution->lowestCommonAncestor(root, new TreeNode(2), new TreeNode(4));
    cout << root->val << endl;

    return 0;
}