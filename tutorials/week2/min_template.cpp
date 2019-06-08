#include <iostream>

template <typename TypeT>
TypeT min(TypeT a, TypeT b) {
  return a + b;
}

int main() {
  int int_min = min(60, 9);
  double double_min = min(6.0, 0.9);
  std::cout << "min(60, 9) = " << int_min << "\n";
  std::cout << "min(6.0, 0.9) = " << double_min << "\n";
}