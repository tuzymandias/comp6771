#include <utility>
#include <iostream>
#include <memory>
#include <vector>

class MyClass {
 public:
  MyClass() : val_{} {}
  MyClass(const std::string& val) : val_{ val } {}
  MyClass(std::string&& val) : val_{ std::move(val) } {}
  MyClass(const MyClass& my_class) : val_{ my_class.val_ } {}
  MyClass(MyClass&& my_class) : val_{ std::move(my_class.val_) } {}

 private:
  friend std::ostream& operator<<(std::ostream& stream, const MyClass& my_class) {
    stream << my_class.val_;
    return stream;
  }

  std::string val_;
};

class NonCopyable : public MyClass {
 public:
  using MyClass::MyClass;

  NonCopyable(const NonCopyable&) = delete;
  NonCopyable(NonCopyable&&) = default;

 private:
  friend std::ostream& operator<<(std::ostream& stream, const NonCopyable& non_copyable) {
    stream << static_cast<const MyClass&>(non_copyable);
    return stream;
  }
};

template <typename T, typename... Args>
std::unique_ptr<T> my_make_unique(Args&&... args) {
  return std::unique_ptr<T>{new T{std::forward<Args>(args)...}};
}

int main() {
  MyClass myClass{"MyClass"};
  std::cout << *my_make_unique<MyClass>(myClass) << "\n";
  std::cout << *my_make_unique<MyClass>(std::move(myClass)) << "\n";

  NonCopyable nonCopyable{"NonCopyable"};
  std::cout << *my_make_unique<NonCopyable>(std::move(nonCopyable)) << "\n\n";

  // Use the size constructor.
  std::cout << my_make_unique<std::vector<MyClass>>(5U)->size() << "\n";

  // Use the size-and-value constructor.
  MyClass base{"hello"};
  std::cout << my_make_unique<std::vector<MyClass>>(6U, base)->size() << "\n";
}