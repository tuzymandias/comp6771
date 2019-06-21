#include "tutorials/week3/car.h"

int Car::object_count_ = 0;

Car::Car(const std::string& manufacturer, int num_seats)
  : manufacturer_{manufacturer}, num_seats_{num_seats} {
  ++object_count_;
}

Car::Car() : Car{"unknown", 4} {}

Car::Car(const Car& source)
  : Car{ source.getManufacturer(), source.getNumSeats() } {}

Car::Car(Car&& source)
  : Car{ std::move(source.manufacturer_), source.num_seats_ } {}

Car::~Car() {
  --object_count_;
}

auto Car::getManufacturer() const -> const std::string& {
  return manufacturer_;
}

auto Car::getNumSeats() const -> int {
  return num_seats_;
}

auto Car::getObjectCount() -> int {
  return object_count_;
}