#include <vector>

template <typename T>
class Vec2DIterator
{

};

template <typename T>
class Vec2D
{
 public:
  using value_type   = T;
  using pointer      = std::add_pointer<T>;
  using reference    = std::add_lvalue_reference<T>;
  using iterator     = Vec2DIterator<value_type>;

  iterator begin() const;
  iterator end() const;

 private:
  using inner_vector = std::vector<value_type>;
  using outer_vector = std::vector<inner_vector>;

  outer_vector data_;
};