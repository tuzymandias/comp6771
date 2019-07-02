#include "iostream"

#include "tutorials/week5/point.h"

int main() {
  Point q{99, -5};
  q[0] = -99;
  std::cout << q[0] << "\n";

  const Point p{99, -5};
  std::cout << p[0] << "\n";

  double distance = Point{ 3, 4 };
  std::cout << distance << "\n";
}