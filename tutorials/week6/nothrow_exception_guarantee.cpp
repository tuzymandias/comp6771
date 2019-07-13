// Nothrow exception guarantee. a.k.a functions that doesn't throw
// Can be marked explicitly by noexcept

#include <stdexcept>

// will not compile if operator+ for TypeT throws
// i.e. function is guaranteed to have nothrow exception guarantee if it is successfully instantiated
template <typename TypeT>
constexpr TypeT my_sum(TypeT a, TypeT b) noexcept {
  return a + b;
}

// guaranteed to not throw even if it isn't marked noexcept
// will just go to UB land
constexpr int int_sum(int a, int b) {
  return a + b;
}

static_assert(noexcept(my_sum(1, 2)));
// the following will fail since int_sum is not marked noexcept
// lesson: the absence of noexcept does not mean that a function throws
static_assert(!noexcept(int_sum(1, 2)));

int main() {

}