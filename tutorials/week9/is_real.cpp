#include <type_traits>
#include <iostream>

namespace traits {

template <typename T>
struct is_real_number {
  static constexpr bool value = std::is_integral_v<T> || std::is_floating_point_v<T>;
};

template <typename T>
constexpr bool is_real_number_v = is_real_number<T>::value;

template <typename T>
struct is_base_real_number {
  static constexpr bool value = is_real_number_v<T>;
};

template <typename T>
struct is_base_real_number<T*> {
  static constexpr bool value = is_base_real_number<T>::value;
};

template <typename T>
struct is_base_real_number<T&> {
  static constexpr bool value = is_base_real_number<T>::value;
};

template <typename T>
struct is_base_real_number<T&&> {
  static constexpr bool value = is_base_real_number<T>::value;
};

template <typename T>
constexpr bool is_base_real_number_v = is_base_real_number<T>::value;

}

int main() {
  using traits::is_real_number_v;

  std::cout << "is_real_number_v<int> = " << is_real_number_v<int> << "\n"; // true
  std::cout << "is_real_number_v<bool> = " << is_real_number_v<bool> << "\n"; // true
  std::cout << "is_real_number_v<float> = " << is_real_number_v<float> << "\n"; // true
  std::cout << "is_real_number_v<int&> = " << is_real_number_v<int&> << "\n"; // true
  std::cout << "is_real_number_v<const int> = " << is_real_number_v<const int> << "\n"; // true
  std::cout << "is_real_number_v<const int&> = " << is_real_number_v<const int&> << "\n"; // true
  std::cout << "is_real_number_v<volatile int&> = " << is_real_number_v<volatile int&> << "\n"; // true
  std::cout << "is_real_number_v<volatile int*> = " << is_real_number_v<volatile int*> << "\n"; // true
  std::cout << "is_real_number_v<volatile int**> = " << is_real_number_v<volatile int**> << "\n"; // true

  using traits::is_base_real_number_v;

  std::cout << "is_base_real_number_v<int> = " << is_base_real_number_v<int> << "\n";
  std::cout << "is_base_real_number_v<bool> = " << is_base_real_number_v<bool> << "\n";
  std::cout << "is_base_real_number_v<float> = " << is_base_real_number_v<float> << "\n";
  std::cout << "is_base_real_number_v<int&> = " << is_base_real_number_v<int&> << "\n";
  std::cout << "is_base_real_number_v<const int> = " << is_base_real_number_v<const int> << "\n";
  std::cout << "is_base_real_number_v<const int&> = " << is_base_real_number_v<const int&> << "\n";
  std::cout << "is_base_real_number_v<volatile int&> = " << is_base_real_number_v<volatile int&> << "\n";
  std::cout << "is_base_real_number_v<volatile int&&> = " << is_base_real_number_v<volatile int&&> << "\n";
  std::cout << "is_base_real_number_v<volatile int*> = " << is_base_real_number_v<volatile int*> << "\n";
  std::cout << "is_base_real_number_v<volatile int**> = " << is_base_real_number_v<volatile int**> << "\n";
  std::cout << "is_base_real_number_v<std::string> = " << is_base_real_number_v<std::string> << "\n";
}