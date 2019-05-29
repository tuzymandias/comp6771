#include <iostream>
#include <tuple>
#include <utility>

int min(int a, int b) {
  return a < b ? a : b;
}

int max(int a, int b) {
  return a > b ? a : b;
}

// takes three integer references as input: a, b, and c.
// when function exits, a b c will be sorted in an ascending order
// for a more solution using std::algorithm see: https://godbolt.org/z/LmowES
// although one might argue that is worse for readability
void sort3(int& a, int& b, int& c) {
  const int min_val = min(a, min(b, c));
  const int max_val = max(a, max(b, c));
  const int mid_val = a + b + c - min_val - max_val;
  a = min_val;
  b = mid_val;
  c = max_val;
}

int main() {
  int a, b, c;
  std::cout << "Please Enter Three Numbers: ";
  std::cin >> a >> b >> c;
  sort3(a, b, c);
  std::cout << "Sorted: " << a << " " << b << " " << c << "\n";
}