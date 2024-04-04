#include <iostream>
#include <vector>
#include <math.h>
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
  時間複雜度：O(n)
*/
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // 使用前序走訪針對每個節點做以下兩項檢查後若通過，則繼續檢查其左右子節點，否則就算不相等
        // 1. 當前節點不存在（表示從葉子節點指進來的）
        // 2. 兩方都有值且兩個值相等
        return p == nullptr && q == nullptr || p != nullptr && q != nullptr && p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

int main(int argc, const char* argv[])
{
    Solution* solution = new Solution();
    TreeNode* p = new TreeNode(4,
        new TreeNode(2,
            new TreeNode(1),
            new TreeNode(3)
        ),
        new TreeNode(7,
            new TreeNode(6),
            new TreeNode(9)
        )
    );
    TreeNode* q = new TreeNode(4,
        new TreeNode(2,
            new TreeNode(1),
            new TreeNode(3)
        ),
        new TreeNode(7,
            new TreeNode(6),
            new TreeNode(9)
        )
    );

    bool result = solution->isSameTree(p, q);
    cout << result << endl;

    return 0;
}