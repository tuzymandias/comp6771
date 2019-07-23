#include <vector>
#include <iostream>
#include <map>

void vectorInvalidation() {
  std::vector<int> my_ints;
  my_ints.push_back(1); // { 1 }
  auto it = my_ints.begin();
  std::cout << "first: " << *it << "\n";

  my_ints.push_back(2); // { 1, 2 }
  std::cout << "first: " << *it << "\n";

  my_ints[0] = 10;
  std::cout << "first: " << *it << "\n";
  std::cout << "actual first: " << my_ints[0] << "\n";
}

int main() {
  vectorInvalidation();
  //https://stackoverflow.com/questions/6438086/iterator-invalidation-rules
}