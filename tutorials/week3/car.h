#ifndef TUTORIALS_WEEK3_CAR_H_
#define TUTORIALS_WEEK3_CAR_H_

#include <string>

class Car {
 public:
  // we use const reference here to save a string copy
  // this can also bind to a temporary string (e.g. Car{ "toyota", 10 })
  Car(const std::string& manufacturer, int num_seats);
  Car();

  ~Car();

  // return a const reference here to keep it const-correct and save a copy.
  // if the user wants to copy they can make the copy themselves
  const std::string& getManufacturer() const;
  // no reason to return a reference to an integer. copying an integer is cheaper than the indirection
  // involved when using references.
  int getNumSeats() const;

  static int getObjectCount();

 private:
  static int object_count_;
  std::string manufacturer_;
  int num_seats_;
};

#endif  // TUTORIALS_WEEK3_CAR_H_
