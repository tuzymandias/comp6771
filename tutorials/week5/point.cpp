#include <ostream>
#include <istream>
#include <iostream>
#include <cassert>
#include <cmath>

#include "tutorials/week5/point.h"

int& Point::operator[](int i) {
  assert(i == 0 || i == 1);
  return coordinates_[i];
}

const int& Point::operator[](int i) const {
  assert(i == 0 || i == 1);
  return coordinates_[i];
}

Point::operator double() const {
  return std::hypot(explicit_coordinates_.x, explicit_coordinates_.y);
}

std::ostream& operator<<(std::ostream& os, const Point& p) {
  os << "(" << p.explicit_coordinates_.x << "," << p.explicit_coordinates_.y << ")";
  return os;
}
std::istream& operator>>(std::istream& is, Point& type) {
  is >> type.explicit_coordinates_.x >> type.explicit_coordinates_.y;
  return is;
}
