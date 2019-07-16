#include <vector>
#include <assert.h>
#include <iostream>
#include "tutorials/week7/string_queue.h"

int main() {
  StringQueue my_queue{ 5 };
  std::vector<std::string> words{ "hello", "world", "three", "more", "words" };
  std::vector<std::string> repeated_words{ };

  for (const std::string& word: words) {
    my_queue.enque(word);
  }

  assert(my_queue.size() == static_cast<int>(words.size()));

  for (const std::string& word: words) {
    if (my_queue.deque() == word) {
      std::cout << "good stuff\n";
    }
    else {
      std::cout << "not good stuff\n";
    }
  }

  assert(my_queue.size() == 0);
}