#ifndef TUTORIALS_WEEK5_POINT_H_
#define TUTORIALS_WEEK5_POINT_H_

#include <ostream>
#include <istream>

class Point {
 public:
  Point() : Point{ 0, 0 } {};
  Point(int x, int y) : explicit_coordinates_{x, y} {};

  int& operator[](int i);
  const int& operator[](int i) const;

  operator double() const;

  friend std::ostream& operator<<(std::ostream& os, const Point& type);
  friend std::istream& operator>>(std::istream& is, Point& type);

 private:
  // Stores explicit x and y coordinates
  struct Coordinates {
    int x;
    int y;
  };

  // Union of a size 2 int array and 2 int struct
  // Layout of array and struct is guaranteed to be the same.
  // This lets you just subscript the coordinates
  union {
    int         coordinates_[2];
    Coordinates explicit_coordinates_;
  };
};

#endif