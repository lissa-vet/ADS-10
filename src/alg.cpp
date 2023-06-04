// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

int factor(int n) {
  if (n <= 1) return 1;
  return factor(n - 1) * n;
}

std::vector<char> getPerm(const Tree& tree, int n) {
  // напишите реализацию
  if (!tree.get_size() || n > factor(tree.get_size()))
    return {};
  if (tree.get_symb() == '*')
    n--;
  int tmp = factor(tree.get_size() - 1);
  std::vector<char> res;
  res.push_back(tree[n / tmp].get_symb());
  std::vector<char> a = getPerm(tree[n / tmp], n % tmp);
  res.insert(res.end(), a.begin(), a.end());
  
  return res;
}
