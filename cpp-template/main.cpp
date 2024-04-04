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
    int f(int x) {
        return 0;
    }
};

int main(int argc, const char* argv[])
{
    Solution* solution = new Solution();
    int input = 1;

    int result = solution->f(input);
    cout << result << endl;

    return 0;
}