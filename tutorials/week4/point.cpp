#include <ostream>
#include <istream>
#include <iostream>

#include "tutorials/week4/point.h"

std::ostream& operator<<(std::ostream& os, const Point& p) {
  os << "(" << p.x_ << "," << p.y_ << ")";
  return os;
}
std::istream& operator>>(std::istream& is, Point& type) {
  is >> type.x_ >> type.y_;
  return is;
}
