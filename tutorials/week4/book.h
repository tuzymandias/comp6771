#ifndef TUTORIALS_WEEK4_BOOK_H_
#define TUTORIALS_WEEK4_BOOK_H_

#include <string>

class Book {
 public:
  Book(const std::string& name, const std::string& author, int isbn, double price);

  int getIsbn() const;
  double getPrice() const;

  bool operator==(const Book&) const;
  bool operator!=(const Book&) const;
  bool operator< (const Book&) const;

  friend std::ostream& operator<<(std::ostream&, const Book&);

  explicit operator std::string() const;

 private:
  std::string name_;
  std::string author_;
  int isbn_;
  double price_;
};

#endif  // TUTORIALS_WEEK4_BOOK_H_
