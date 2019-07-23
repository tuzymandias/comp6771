#include <algorithm>
#include "tutorials/week8/rope.h"

void Rope::iterator::advance() {
  ++inner_it_;
  while(outer_it_ != outer_end_ && inner_it_ == outer_it_->end()) {
    ++outer_it_;
    if (outer_it_ != outer_end_) {
      inner_it_ = outer_it_->begin();
    }
    else {
      inner_it_ = inner_iterator{};
    }
  }
}

auto Rope::iterator::operator*() const -> reference {
  return *inner_it_;
}

auto Rope::iterator::operator++() -> iterator& {
  advance();
  return *this;
}

auto Rope::begin() -> iterator {
  if (auto first = std::find_if(rope_.begin(), rope_.end(), [] (const std::string& s) { return !s.empty(); }); first != rope_.end()) {
    return iterator{ first, rope_.end() };
  }
  return end();
}

auto Rope::end() -> iterator {
  return iterator { rope_.end() };
}