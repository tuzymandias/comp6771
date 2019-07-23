#ifndef TUTORIALS_WEEK8_ROPE_H_
#define TUTORIALS_WEEK8_ROPE_H_

#include <string>
#include <utility>
#include <vector>

class Rope {
  using storage                      = std::vector<std::string>;

 public:
  explicit Rope(std::vector<std::string> rope): rope_{std::move(rope)} {}

  class iterator {
   public:
    using outer_iterator    = typename storage::iterator;
    using inner_iterator    = typename outer_iterator::value_type::iterator;
    using value_type        = typename inner_iterator::value_type;
    using reference         = std::add_lvalue_reference_t<value_type>;
    using pointer           = std::add_pointer_t<value_type>;
    using iterator_category = std::bidirectional_iterator_tag;
    using difference_type   = int;

    iterator(outer_iterator it, outer_iterator end)
      : outer_it_ { it  }
      , outer_end_{ end }
      , inner_it_ { it->begin() }
    {}

    iterator(outer_iterator end)
      : outer_it_ { end }
      , outer_end_{ end }
      , inner_it_ {}
    {}

    reference operator*() const;
    iterator& operator++();
    iterator operator++(int) {
      auto copy{*this};
      ++(*this);
      return copy;
    }
    // This one isn't strictly required, but it's nice to have.
    pointer operator->() const { return &(operator*()); }

    friend bool operator==(const iterator& lhs, const iterator& rhs) {
      return lhs.outer_it_ == rhs.outer_it_ &&
             lhs.inner_it_ == rhs.inner_it_;
    };
    friend bool operator!=(const iterator& lhs, const iterator& rhs) { return !(lhs == rhs); }

   private:
    void advance();

    outer_iterator outer_it_;
    outer_iterator outer_end_;
    inner_iterator inner_it_;
  };

  iterator begin();
  iterator end();

 private:
  storage rope_;
};


#endif  // TUTORIALS_WEEK8_ROPE_H_
