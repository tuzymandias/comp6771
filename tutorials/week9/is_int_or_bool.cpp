#include <type_traits>
#include <iostream>

namespace traits {

template <typename T>
struct is_int_or_bool {
  static constexpr bool value = std::is_same_v<T, int> || std::is_same_v<T, bool>;
};

template <typename T>
constexpr bool is_int_or_bool_v = is_int_or_bool<T>::value;

template <typename T>
struct is_base_int_or_bool {
  static constexpr bool value = std::is_same_v<T, int> || std::is_same_v<T, bool>;
};

template <typename T>
struct is_base_int_or_bool<T*> {
  static constexpr bool value = is_base_int_or_bool<T>::value;
};

template <typename T>
struct is_base_int_or_bool<T&> {
  static constexpr bool value = is_base_int_or_bool<T>::value;
};

template <typename T>
struct is_base_int_or_bool<const T> {
  static constexpr bool value = is_base_int_or_bool<T>::value;
};

template <typename T>
struct is_base_int_or_bool<volatile T> {
  static constexpr bool value = is_base_int_or_bool<T>::value;
};

template <typename T>
constexpr bool is_base_int_or_bool_v = is_base_int_or_bool<T>::value;

}

int main() {
  using traits::is_int_or_bool_v;

  std::cout << "is_int_or_bool_v<int> = " << is_int_or_bool_v<int> << "\n";
  std::cout << "is_int_or_bool_v<bool> = " << is_int_or_bool_v<bool> << "\n";
  std::cout << "is_int_or_bool_v<float> = " << is_int_or_bool_v<float> << "\n";
  std::cout << "is_int_or_bool_v<int&> = " << is_int_or_bool_v<int&> << "\n";
  std::cout << "is_int_or_bool_v<const int> = " << is_int_or_bool_v<const int> << "\n";
  std::cout << "is_int_or_bool_v<const int&> = " << is_int_or_bool_v<const int&> << "\n";
  std::cout << "is_int_or_bool_v<volatile int&> = " << is_int_or_bool_v<volatile int&> << "\n";
  std::cout << "is_int_or_bool_v<volatile int*> = " << is_int_or_bool_v<volatile int*> << "\n";
  std::cout << "is_int_or_bool_v<volatile int**> = " << is_int_or_bool_v<volatile int**> << "\n";

  using traits::is_base_int_or_bool_v;
  
  std::cout << "is_base_int_or_bool_v<int> = " << is_base_int_or_bool_v<int> << "\n";
  std::cout << "is_base_int_or_bool_v<bool> = " << is_base_int_or_bool_v<bool> << "\n";
  std::cout << "is_base_int_or_bool_v<float> = " << is_base_int_or_bool_v<float> << "\n";
  std::cout << "is_base_int_or_bool_v<int&> = " << is_base_int_or_bool_v<int&> << "\n";
  std::cout << "is_base_int_or_bool_v<const int> = " << is_base_int_or_bool_v<const int> << "\n";
  std::cout << "is_base_int_or_bool_v<const int&> = " << is_base_int_or_bool_v<const int&> << "\n";
  std::cout << "is_base_int_or_bool_v<volatile int&> = " << is_base_int_or_bool_v<volatile int&> << "\n";
  std::cout << "is_base_int_or_bool_v<volatile int*> = " << is_base_int_or_bool_v<volatile int*> << "\n";
  std::cout << "is_base_int_or_bool_v<volatile int**> = " << is_base_int_or_bool_v<volatile int**> << "\n";
}