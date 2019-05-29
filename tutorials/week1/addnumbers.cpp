#include <iostream>

// further reading on optimization
// https://godbolt.org/z/h_AMu1
int sum(int first_operand, int second_operand) {
  return first_operand + second_operand;
}

int main() {
  std::cout << "Please enter two numbers: ";
  int first_number, second_number;
  std::cin >> first_number >> second_number;
  const int sum_of_numbers = sum(first_number, second_number);
  std::cout << "Sum: " << sum_of_numbers << "\n";
}