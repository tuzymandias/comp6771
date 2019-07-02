#include <ostream>
#include <istream>
#include <iostream>
#include <cassert>

#include "tutorials/week5/point.h"

int& Point::operator[](int i) {
  assert(i == 0 || i == 1);
  if (i == 0) {
    return this->x_;
  } else {
    return this->y_;
  }
}

std::ostream& operator<<(std::ostream& os, const Point& p) {
  os << "(" << p.x_ << "," << p.y_ << ")";
  return os;
}
std::istream& operator>>(std::istream& is, Point& type) {
  is >> type.x_ >> type.y_;
  return is;
}
