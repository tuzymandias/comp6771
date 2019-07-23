#include <iostream>

#include "tutorials/week8/rope.h"

int main() {
  std::vector<Rope> ropes{
      Rope{{"a"}},
      Rope{{"abc"}},
      Rope{{"abc"}},
      Rope{{"abc", "def"}},
      Rope{{"abc", "", "def"}},
      Rope{{""}},
      Rope{{"", "abc", "def", ""}},
      Rope{{}}
  };

  // TODO(tutorial): make this support const auto& rope, if you have time.
  for (auto& rope : ropes) {
    std::cout << "Rope: \"";
    for (char& letter : rope) {
      std::cout << letter;
    }
    std::cout << "\"\n";
  }

  std::cout << "CONST PRINT\n";
  for (const auto& rope : ropes) {
    std::cout << "Rope: \"";
    for (const char& letter : rope) {
      std::cout << letter;
    }
    std::cout << "\"\n";
  }

  std::cout << "REVERSE PRINT\n";
  for (auto it = ropes.rbegin(); it != ropes.rend(); ++it) {
    std::cout << "Rope: \"";
    for (auto rope_it = it->crbegin(); rope_it != it->crend(); ++rope_it) {
      std::cout << *rope_it;
    }
    std::cout << "\"\n";
  }

  std::cout << "CONST REVERSE PRINT\n";
  for (auto it = ropes.crbegin(); it != ropes.crend(); ++it) {
    std::cout << "Rope: \"";
    for (auto rope_it = it->crbegin(); rope_it != it->crend(); ++rope_it) {
      std::cout << *rope_it;
    }
    std::cout << "\"\n";
  }
}


