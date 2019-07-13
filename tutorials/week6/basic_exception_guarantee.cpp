#include <vector>

template <typename TypeT>
void extendVector(std::vector<TypeT>& target, const std::vector<TypeT>& source) {
  const int size_to_reserve = target.size() + source.size();
  target.reserve(size_to_reserve);
  // can throw if TypeT's copy assignment/constructor operator thows
  // if it does, target's internal size would not be the same as it was when it entered the function
  // however the program is still in a valid state and clean up can be done
  std::copy(source.begin(), source.end(), std::back_inserter(target));
}

int main() {

}