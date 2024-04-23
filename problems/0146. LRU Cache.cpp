#include "../shared/shared.h"
#include <deque>
#include <iostream>
#include <math.h>
#include <unordered_map>
using namespace std;

struct Node {
  int key;
  int value;
  Node* previous;
  Node* next;
};

/*
  時間複雜度：O(1)
*/
class LRUCache {
public:
  unordered_map<int, Node*> cache; // key-value 對應表
  Node* head = nullptr; //最近使用的節點
  Node* tail = nullptr; //最遠使用的節點
  int capacity; // Cache 容量

  LRUCache(int capacity) { this->capacity = capacity; }

  void moveNodeToRecent(Node* node) {
    if (node == head) {
      return;
    }

    if (node == tail) {
      tail = node->previous;
    }

    //把原先在節點前後的節點接起來
    Node* previous = node->previous;
    Node* next = node->next;

    if (previous != nullptr) {
      previous->next = next;
    }

    if (next != nullptr) {
      next->previous = previous;
    }

    //把節點移到 head 之前
    node->previous = nullptr;
    node->next = head;
    head->previous = node;
    head = head->previous;
  }

  int get(int key) {
    if (!cache.count(key)) {
      return -1;
    }

    //更新最近使用資料清單
    Node* node = cache[key];
    moveNodeToRecent(node);

    return cache[key]->value;
  }

  void put(int key, int value) {
    //若 Key 已存在就更新現有資料就好
    if (cache.count(key)) {
      Node* node = cache[key];
      node->value = value;

      //更新最近使用資料清單
      moveNodeToRecent(node);
      return;
    }

    Node* node = new Node();
    node->key = key;
    node->value = value;
    node->previous = nullptr;
    node->next = nullptr;

    if (cache.size() == 0) {
      head = node;
      tail = node;
      cache[key] = node;
      return;
    }

    //若容量滿了就先移除舊有資料
    if (cache.size() >= capacity) {
      cache.erase(tail->key);
      tail = tail->previous != nullptr ? tail->previous : node;
      delete tail->next; //不確定有沒有用
      tail->next = nullptr;
    }

    //新增資料
    node->next = head;
    head->previous = node;
    head = node;
    cache[key] = node;
  }
};

int main(int argc, const char* argv[]) {
  LRUCache* obj = new LRUCache(1);
  obj->put(2, 1);
  cout << obj->get(2) << endl;
  obj->put(3, 2);
  cout << obj->get(2) << endl;
  cout << obj->get(3) << endl;

  return 0;
}