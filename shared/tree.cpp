#include "shared.h"
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

TreeNode* vectorToTree(vector<int> vec) {
  if (!vec.size()) {
    return nullptr;
  }

  TreeNode* head = new TreeNode(vec[0]);
  queue<TreeNode*> q;
  q.push(head);
  int index = 1;

  while (!q.empty()) {
    TreeNode* currentNode = q.front();
    q.pop();

    if (index < vec.size()) {
      currentNode->left = new TreeNode(vec[index++]);
      q.push(currentNode->left);
    }

    if (index < vec.size()) {
      currentNode->right = new TreeNode(vec[index++]);
      q.push(currentNode->right);
    }
  }

  return head;
}

/*
  印出整棵樹
*/
void printTree(TreeNode* head) {
  if (head == nullptr) {
    return;
  }

  vector<int> vec;
  queue<TreeNode*> q;
  q.push(head);

  while (!q.empty()) {
    TreeNode* currentNode = q.front();
    q.pop();

    vec.push_back(currentNode->val);

    if (currentNode->left != nullptr) {
      q.push(currentNode->left);
    }

    if (currentNode->right != nullptr) {
      q.push(currentNode->right);
    }
  }

  int index = 1;
  int layer = 1;
  while (index <= vec.size()) {
    cout << vec[index - 1] << ' ';
    if (++index == (1 << layer)) {
      layer++;
      cout << endl;
    }
  }
  cout << endl;
}
