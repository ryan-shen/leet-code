// #include "../shared/shared.h"
#include <algorithm>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string.h>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

struct TrieNode {
  unordered_map<char, TrieNode*> map;
  bool isWord;
};

bool search(TrieNode* root, string s) {
  TrieNode* currentNode = root;
  for (int i = 0; i < s.length(); i++) {
    if (!currentNode->map.contains(s[i])) {
      return false;
    }

    currentNode = currentNode->map[s[i]];
  }
  return currentNode->isWord;
}

void insert(TrieNode* root, string s) {
  TrieNode* currentNode = root;
  for (int i = 0; i < s.length(); i++) {
    if (!currentNode->map.contains(s[i])) {
      currentNode->map[s[i]] = new TrieNode();
    }

    currentNode = currentNode->map[s[i]];
  }
  currentNode->isWord = true;
}

bool remove(TrieNode* root, string s, int pos) {
  if (pos >= s.length()) {
    root->isWord = false;
    return root->map.empty();
  }

  if (!root->map.contains(s[pos])) {
    return false;
  }

  if (remove(root, s, pos + 1)) {
    root->map.erase(s[pos]);
    return root->map.empty();
  }

  return false;
}

void remove(TrieNode* root, string s) { remove(root, s, 0); }

void print(TrieNode* root) {
  queue<TrieNode*> q;
  q.push(root);

  while (!q.empty()) {
    TrieNode* currentNode = q.front();
    q.pop();

    cout << "map: ";
    for (auto it = currentNode->map.begin(); it != currentNode->map.end(); it++) {
      if (it == currentNode->map.begin()) {
        cout << ", ";
      }

      cout << (*it).first;
      q.push((*it).second);
    }
    cout << "isWord: " << currentNode->isWord << endl;
  }
}

int main(int argc, const char* argv[]) {
  TrieNode* root = new TrieNode();

  insert(root, "cat");
  cout << search(root, "cat2") << endl;
  cout << search(root, "cat") << endl;
  // print(root);
  return 0;
}