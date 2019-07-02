#ifndef TUTORIALS_WEEK5_POINT_H_
#define TUTORIALS_WEEK5_POINT_H_

#include <ostream>
#include <istream>

class Point {
 public:
  Point() : Point{ 0, 0 } {};
  Point(int x, int y) : x_{x}, y_{y} {};

  int& operator[](int i);
  const int& operator[](int i) const;

  friend std::ostream& operator<<(std::ostream& os, const Point& type);
  friend std::istream& operator>>(std::istream& is, Point& type);

 private:
  int x_;
  int y_;
};

#endif