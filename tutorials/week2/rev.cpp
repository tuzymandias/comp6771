#include <iostream>
#include <vector>

void PrintInts(std::vector<int> ints) {
  for (auto i = 0u; i < ints.size(); ++i) {
    std::cout << ints.at(i) << " ";
  }
  std::cout << "\n";

  for (const auto& temp : ints) {
    std::cout << temp << " ";
  }
  std::cout << "\n";

  for (auto iter = ints.cbegin();
       iter != ints.cend(); ++iter) {
    std::cout << *iter << " ";
  }
  std::cout << "\n";
}

// might not const correct, not fully tested
class ReverseAdaptor {
 public:
  using iterator = typename std::vector<int>::const_reverse_iterator;

  ReverseAdaptor(const std::vector<int>& ints)
    : ints_(ints)
  {}

  iterator begin() const { return ints_.rbegin(); }
  iterator end() const { return ints_.rend(); }

 private:
  const std::vector<int>& ints_;
};

void ReversePrintInts(std::vector<int> ints) {
  for (auto i = ints.size(); i > 0; --i) {
    std::cout << ints.at(i - 1) << " ";
  }
  std::cout << "\n";

  // this type of loop cannot be reversed, so we have to make a workaround. not recommended
  // this type of loop is syntactic sugar for
  // for (auto it = container.begin(); it != container.end(); ++it) {
  //   const auto& ref = *it;
  //   /* insert code here */
  // }
  // so if we can create a wrapper that wraps around our vector, and where begin() is the equivalent
  // of vector.rbegin() and where end() is equivalent to vector.rend(), we can reverse iterate using
  // this loop type.
  for (const auto& temp : ReverseAdaptor{ ints }) {
    std::cout << temp << " ";
  }
  std::cout << "\n";

  for (auto iter = ints.crbegin();
       iter != ints.crend(); ++iter) {
    std::cout << *iter << " ";
  }
  std::cout << "\n";
}

int main() {
  std::vector<int> temperatures{32, 34, 33, 28, 35, 28, 34};
  PrintInts(temperatures);
  ReversePrintInts(temperatures);
}