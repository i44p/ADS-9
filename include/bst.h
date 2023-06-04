// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

#include <algorithm>

template <typename T>
class BST {
 public:
  BST() : root(nullptr) {}

  ~BST() {
    if (root) delTree(root);
  }

  int depth() const { return maxDepth(root) - 1; }

  int search(T value) const {
    for (Node* current = root; current;
         current = value < current->value ? current->left : current->right)
      if (current->value == value) return current->count;

    return -1;
  }

  void insert(T value) { root = insertNode(root, value); }

 private:
  struct Node {
    T value;
    int count;
    Node* left;
    Node* right;
  };

  Node* root;

  int maxDepth(Node* node) const {
    return node ? std::max(maxDepth(node->left), maxDepth(node->right)) + 1 : 0;
  }

  Node* insertNode(Node* node, T value) {
    if (node == nullptr) {
      node = new Node;
      node->value = value;
      node->count = 1;
      node->left = node->right = nullptr;
    } else if (value == node->value) {
      node->count++;
    } else if (node->value > value) {
      node->left = insertNode(node->left, value);
    } else if (node->value < value) {
      node->right = insertNode(node->right, value);
    }
    return node;
  }

  void delTree(Node* node) {
    if (node) {
      delTree(node->left);
      delTree(node->right);
      delete node;
    }
  }
};

#endif  // INCLUDE_BST_H_
