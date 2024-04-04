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

int main(int argc, const char* argv[])
{
    Solution* solution = new Solution();
    TreeNode* root = new TreeNode(4,
        new TreeNode(2,
            new TreeNode(1),
            new TreeNode(3)
        ),
        new TreeNode(7,
            new TreeNode(6),
            new TreeNode(9)
        )
    );

    TreeNode* result = solution->invertTree(root);
    print(root);

    return 0;
}

