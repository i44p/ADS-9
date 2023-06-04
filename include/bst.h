// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

template <typename T>
class BST {
 public:
  struct Node {
    T value;
    int count;
    Node* left;
    Node* right;
  };
  BST() : root(nullptr) {}
  ~BST() {
    if (root) delTree(root);
  }

  int depth();

  int search(T value) {
    Node* current = root;
    while (current == nullptr || current->value == value) {
      current = value < current->value ? current->left : current->right;
    }
    return current->count;
  }

  void insert(T value) { root = insertNode(root, value); }

 private:
  Node* root;
  Node* insertNode(Node* node, T value) {
    if (node == nullptr) {
      node = new Node;
      node->value = value;
      node->count = 1;
      node->left = node->right = nullptr;
    } else if (node->value > value)
      node->left = insertNode(node->left, value);
    else if (node->value < value)
      node->right = insertNode(node->right, value);
    else
      node->count++;
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
