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
    vector<int> leftTraversalValues;
    vector<int> rightTraversalValues;
    bool isSymmetric(TreeNode* root) {
        leftTraversal(root);
        rightTraversal(root);

        for (size_t i = 0; i < leftTraversalValues.size(); i++)
        {
            if (leftTraversalValues[i] != rightTraversalValues[i]) {
                return false;
            }
        }

        return true;
    }

    void leftTraversal(TreeNode* root) {
        if (root == nullptr) {
            leftTraversalValues.push_back(-101);
            return;
        }

        leftTraversalValues.push_back(root->val);
        leftTraversal(root->left);
        leftTraversal(root->right);
    }

    void rightTraversal(TreeNode* root) {
        if (root == nullptr) {
            rightTraversalValues.push_back(-101);
            return;
        }

        rightTraversalValues.push_back(root->val);
        rightTraversal(root->right);
        rightTraversal(root->left);
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

    bool result = solution->isSymmetric(root);
    cout << result << endl;

    return 0;
}