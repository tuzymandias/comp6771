#include <tuple>
#include <sstream>
#include "book.h"

Book::Book(const std::string& name, const std::string& author, int isbn, double price)
  : name_{name}, author_{author}, isbn_{isbn}, price_{price} {}

int Book::getIsbn() const {
  return isbn_;
}

double Book::getPrice() const {
  return price_;
}

bool Book::operator==(const Book& other) const {
  const auto other_data = std::tie(other.name_, other.author_, other.isbn_, other.price_);
  const auto this_data  = std::tie(name_, author_, isbn_, price_);
  return other_data == this_data;
}

bool Book::operator!=(const Book& other) const {
  return !(*this == other);
}

bool Book::operator<(const Book& other) const {
  return isbn_ < other.isbn_;
}

Book::operator std::string() const {
  std::ostringstream buffer;
  buffer << name_ << ", " << author_;
  return buffer.str();
}

std::ostream& operator<<(std::ostream& out, const Book& book) {
  out << "name: " << book.name_ << " author: " << book.author_ << " isbn: " << book.isbn_ << " price: " << book.price_;
  return out;
}
