#include <algorithm>
#include "tutorials/week8/rope.h"

auto Rope::begin() -> iterator {
  if (auto first = std::find_if(rope_.begin(), rope_.end(), [] (const std::string& s) { return !s.empty(); }); first != rope_.end()) {
    return iterator{ first, rope_.end(), first->begin() };
  }
  return end();
}

auto Rope::end() -> iterator {
  return iterator { rope_.end(), rope_.end(), {} };
}

auto Rope::cbegin() const -> const_iterator {
  if (auto first = std::find_if(rope_.begin(), rope_.end(), [] (const std::string& s) { return !s.empty(); }); first != rope_.end()) {
    return const_iterator{ first, rope_.end(), first->begin() };
  }
  return end();
}

auto Rope::cend() const -> const_iterator {
  return const_iterator { rope_.end(), rope_.end(), {} };
}

auto Rope::begin() const -> const_iterator {
  return cbegin();
}

auto Rope::end() const -> const_iterator {
  return cend();
}

auto Rope::rbegin() -> reverse_iterator {
  if (auto first = std::find_if(rope_.rbegin(), rope_.rend(), [] (const std::string& s) { return !s.empty(); }); first != rope_.rend()) {
    return reverse_iterator{ first, rope_.rend(), first->rbegin() };
  }
  return rend();
}

auto Rope::rend() -> reverse_iterator {
  return reverse_iterator { rope_.rend(), rope_.rend(), {} };
}

auto Rope::crbegin() const -> const_reverse_iterator {
  if (auto first = std::find_if(rope_.rbegin(), rope_.rend(), [] (const std::string& s) { return !s.empty(); }); first != rope_.rend()) {
    return const_reverse_iterator{ first, rope_.rend(), first->rbegin() };
  }
  return crend();
}

auto Rope::crend() const -> const_reverse_iterator {
  return const_reverse_iterator { rope_.rend(), rope_.rend(), {} };
}

auto Rope::rbegin() const -> const_reverse_iterator {
  return crbegin();
}

auto Rope::rend() const -> const_reverse_iterator {
  return crend();
}
