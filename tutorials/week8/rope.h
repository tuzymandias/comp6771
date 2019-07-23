#ifndef TUTORIALS_WEEK8_ROPE_H_
#define TUTORIALS_WEEK8_ROPE_H_

#include <string>
#include <utility>
#include <vector>

// type is conditional based on ReverseT and ConstnessT
// ReverseT ConstnessT Type
// True     True       const_reverse_iterator
// True     False      reverse_iterator
// False    True       const_iterator
// False    False      iterator
template <typename StorageT, bool ReverseT, bool ConstnessT>
struct conditional_iterator
{
  using type = std::conditional_t<ReverseT,
                                  typename StorageT::const_reverse_iterator,
                                  typename StorageT::const_iterator>;
};

template <typename StorageT, bool ReverseT>
struct conditional_iterator<StorageT, ReverseT, false>
{
  using type = std::conditional_t<ReverseT,
                                  typename StorageT::reverse_iterator,
                                  typename StorageT::iterator>;
};

// helper alias to prevent using typename
template <typename StorageT, bool ReverseT, bool ConstnessT>
using conditional_iterator_t = typename conditional_iterator<StorageT, ReverseT, ConstnessT>::type;

// const T if Constness == false
// T otherwise
template <typename T, bool ConstnessT>
struct conditional_const
{
  using type = const T;
};

template <typename T>
struct conditional_const<T, false>
{
  using type = T;
};

// helper alias to prevent using typename
template <typename T, bool ConstnessT>
using conditional_const_t = typename conditional_const<T, ConstnessT>::type;

class Rope {
  using storage                      = std::vector<std::string>;

 public:
  explicit Rope(std::vector<std::string> rope): rope_{std::move(rope)} {}

  template <bool ReverseT, bool ConstnessT>
  class iterator_t {
   public:
    using outer_iterator    = conditional_iterator_t<storage, ReverseT, ConstnessT>;
    using outer_value_type  = typename outer_iterator::value_type;
    using inner_iterator    = conditional_iterator_t<outer_value_type, ReverseT, ConstnessT>;
    using value_type        = typename inner_iterator::value_type;
    using reference         = conditional_const_t<value_type, ConstnessT>&;
    using pointer           = conditional_const_t<value_type, ConstnessT>*;
    using iterator_category = std::bidirectional_iterator_tag;
    using difference_type   = int;

    iterator_t(outer_iterator outer_it, outer_iterator outer_end, inner_iterator inner_it)
        : outer_it_ { outer_it }
        , outer_end_{ outer_end }
        , inner_it_ { inner_it }
    {}

    reference operator*() const;
    iterator_t& operator++();
    iterator_t operator++(int) {
      auto copy{*this};
      ++(*this);
      return copy;
    }
    // This one isn't strictly required, but it's nice to have.
    pointer operator->() const { return &(operator*()); }

    friend bool operator==(const iterator_t& lhs, const iterator_t& rhs) {
      return lhs.outer_it_ == rhs.outer_it_ &&
          lhs.inner_it_ == rhs.inner_it_;
    };
    friend bool operator!=(const iterator_t& lhs, const iterator_t& rhs) { return !(lhs == rhs); }

   private:
    void advance();
    // not very elegant design, ideally you want to abstract these details
    bool inner_end() const {
      if constexpr (ReverseT) {
        return inner_it_ == outer_it_->rend();
      }
      else {
        return inner_it_ == outer_it_->end();
      }
    };

    // not very elegant design, ideally you want to abstract these details
    inner_iterator inner_begin() const {
      if constexpr (ReverseT) {
        return outer_it_->rbegin();
      }
      else {
        return outer_it_->begin();
      }
    };

    outer_iterator outer_it_;
    outer_iterator outer_end_;
    inner_iterator inner_it_;
  };

  using iterator               = iterator_t<false, false>;
  using const_iterator         = iterator_t<false, true>;
  using reverse_iterator       = iterator_t<true, false>;
  using const_reverse_iterator = iterator_t<true, true>;

  iterator begin();
  iterator end();

  const_iterator cbegin() const;
  const_iterator cend() const;
  const_iterator begin() const;
  const_iterator end() const;

  reverse_iterator rbegin();
  reverse_iterator rend();

  const_reverse_iterator crbegin() const;
  const_reverse_iterator crend() const;
  const_reverse_iterator rbegin() const;
  const_reverse_iterator rend() const;

 private:
  storage rope_;
};

template <bool ConstnessT, bool ReverseT>
void Rope::iterator_t<ConstnessT, ReverseT>::advance() {
  ++inner_it_;
  while(outer_it_ != outer_end_ && inner_end()) {
    ++outer_it_;
    if (outer_it_ != outer_end_) {
      inner_it_ = inner_begin();
    }
    else {
      inner_it_ = inner_iterator{};
    }
  }
}

template <bool ConstnessT, bool ReverseT>
auto Rope::iterator_t<ConstnessT, ReverseT>::operator*() const -> reference {
  return *inner_it_;
}

template <bool ConstnessT, bool ReverseT>
auto Rope::iterator_t<ConstnessT, ReverseT>::operator++() -> iterator_t& {
  advance();
  return *this;
}

#endif  // TUTORIALS_WEEK8_ROPE_H_
