#include <vector>
#include <iostream>
#include <map>

void vectorInvalidation() {
  std::vector<int> my_ints;
  my_ints.push_back(1); // { 1 }
  auto it = my_ints.begin();
  std::cout << "first: " << *it << "\n";
}

int main() {
  vectorInvalidation();
  //https://stackoverflow.com/questions/6438086/iterator-invalidation-rules
}