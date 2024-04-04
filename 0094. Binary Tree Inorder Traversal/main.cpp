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
  空間複雜度：O(n)
*/
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        // 使用中序走訪，並將走訪過的每個節點存到 vec 裡面
        vector<int> vec;
        traverse(root, vec);
        return vec;
    }

    void traverse(TreeNode* root, vector<int>& vec) {
        if (root == nullptr) {
            return;
        }

        traverse(root->left, vec);
        vec.push_back(root->val);
        traverse(root->right, vec);
    }
};

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

    vector<int> result = solution->inorderTraversal(root);
    for (auto&& i : result)
    {
        cout << i << " ";
    }

    return 0;
}