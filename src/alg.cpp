// Copyright 2021 NNTU-CS
#include <algorithm>
#include <cctype>
#include <fstream>

#include "bst.h"

BST<std::string> makeTree(const char* filename) {
  std::ifstream file(filename);

  BST<std::string> bst;

  std::string word;

  for (char ch = file.get(); !file.eof(); file.get(ch)) {
    if (std::isalpha(ch)) {
      word += std::tolower(ch);
    } else if (word.size()) {
      bst.insert(word);
      word.clear();
    }
  }

  file.close();

  return bst;
}
