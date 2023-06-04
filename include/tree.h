// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>

class Tree {
 private:
  std::vector<Tree*> child;
  char symb;

  explicit Tree(char temp) : symb(temp) {}
  void addNode(std::vector<char> arr) {
    for (int i = 0; i < arr.size(); i++) {
      std::vector<char> temp = arr;
      child.push_back(new Tree(temp[i]));
      temp.erase(temp.begin() + i);
      child[i]->addNode(temp);
    }
  }

 public:
  explicit Tree(std::vector<char> vect) {
    symb = '*';
    addNode(vect);
  }
  int get_size() const {
    return child.size();
  }
  char get_symb() const {
    return symb;
  }
  Tree& operator[](int n) const {
    return *child[n];
  }
};

#endif  // INCLUDE_TREE_H_
