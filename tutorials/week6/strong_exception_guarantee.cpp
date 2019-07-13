
#include <cstddef>
#include <array>

template <typename TypeT, std::size_t CapacityT>
class FixedVector {
 public:
  FixedVector() = default;

  // if this function throws, nothing changes.
  void push_back(TypeT&& rval) {
    if (size_ >= CapacityT) {
      std::runtime_error("vector already full");
    }

    storage_[size_] = rval;
    ++size_;
  }

 private:
  std::array<TypeT, CapacityT> storage_ { };
  std::size_t                  size_ { 0 };
};


int main() {

}