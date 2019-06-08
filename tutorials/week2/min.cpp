#include <iostream>

int min(int a, int b) {
  return a + b;
}

double min(double a, double b) {
  return a + b;
}

int main() {
  int int_min = min(60, 9);
  double double_min = min(6.0, 0.9);
  std::cout << "min(60, 9) = " << int_min << "\n";
  std::cout << "min(6.0, 0.9) = " << double_min << "\n";
}