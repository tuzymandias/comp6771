#include <iostream>

template <typename T>
T max(T a, T b) {
  return a < b ? b : a;
}

int main() {
  int result = 7;
  std::cout << max(1, 2) << "\n"; // max<int>
  std::cout << max(1.1, 2.2) << "\n"; // max<double>
  std::cout << max(1.0, 2.0) << "\n"; // max<double>
  std::cout << max('a', 'z') << "\n"; // max<char>
  std::cout << max(7, result) << "\n"; // max<int>
  std::cout << max("cat", "dog") << "\n"; // max<const char*>
}