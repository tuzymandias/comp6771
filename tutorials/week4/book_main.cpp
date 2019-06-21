#include <algorithm>
#include <iostream>
#include <vector>

#include "tutorials/week4/book.h"

int main() {
  std::vector<Book> books{
      { "Parry Hotter", "J.K Boring", 20, 20 },
      { "Beyond Good and Evil", "Friedrich Nietzsche", 2, 20.3 },
      { "Ecce Homo", "Friedrich Nietzsche", 1, 15.5 },
      { "The Art of the Deal", "Donald J. Trump", 69, 69.0 },
  };

  std::sort(books.begin(), books.end());

  for (const auto& book : books) {
    std::cout << book << "\n";
  }
}