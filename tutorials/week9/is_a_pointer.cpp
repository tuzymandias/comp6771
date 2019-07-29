#include <iostream>

namespace traits {

template <typename T>
struct is_a_pointer {
  static constexpr bool value = false;
};

template <typename T>
struct is_a_pointer<T*> {
  static constexpr bool value = true;
};

template <typename T>
constexpr bool is_a_pointer_v = is_a_pointer<T>::value;

}

int main() {
  using traits::is_a_pointer;
  std::cout << "is_a_pointer<int>::value = " << is_a_pointer<int>::value << "\n";
  std::cout << "is_a_pointer<int*>::value = " << is_a_pointer<int*>::value << "\n";
  std::cout << "is_a_pointer<int**>::value = " << is_a_pointer<int**>::value << "\n";

  using traits::is_a_pointer_v;
  std::cout << "is_a_pointer_v<int> = " << is_a_pointer_v<int> << "\n";
  std::cout << "is_a_pointer_v<int*> = " << is_a_pointer_v<int*> << "\n";
  std::cout << "is_a_pointer_v<int**> = " << is_a_pointer_v<int**> << "\n";
}