#include <iostream>

int main() {
  // does not perform exactly like the C program
  // std::string is not the same as a char array, the former dynamically allocates
  // while the other is a constant sized array that will be allocated in the stack
  std::string buffer;
  std::getline(std::cin, buffer);
  std::cout << buffer << "\n";
}