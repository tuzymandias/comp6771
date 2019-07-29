#include <iostream>

constexpr int factorial (int n) {
  return n > 0 ? n * factorial( n - 1 ) : 1;
}

template <int Value>
constexpr int tmp_factorial() {
  if constexpr (Value > 0) {
    return Value * tmp_factorial<Value - 1>();
  }
  else {
    return 1;
  }
}

int main() {
  std::cout << factorial(6) << std::endl;
  std::cout << tmp_factorial<6>() << std::endl;
}