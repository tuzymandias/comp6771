#include <iostream>
#include <set>
#include <unordered_set>

template <typename T, template <typename...> typename StorageT = std::set>
class SillySet {
 public:
  void insert(T t) { set_.insert(t); };
  bool erase(T t) { return set_.erase(t); };

  friend std::ostream& operator<<(std::ostream& stream, const SillySet& silly_set) {
    for (const auto& vals: silly_set.set_) {
      stream << vals;
    }
    return stream;
  }

 private:
  StorageT<T> set_;
};

int main() {

  SillySet<float> s;
  SillySet<int, std::unordered_set> us;

  s.insert(5.4);
  s.insert(6.2);
  s.erase(5.4);
  std::cout << s << "\n";

  us.insert(5);
  us.insert(6);
  us.erase(5);

  std::cout << us << "\n";

}
