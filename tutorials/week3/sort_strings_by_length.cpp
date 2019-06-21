#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

int main() {
  std::vector<std::string> vec { "love", "functions" , "We", "lambda"};
  const auto length_cmp = [](const std::string& left, const std::string& right) {
    return left.size() < right.size();
  };
  std::sort(vec.begin(), vec.end(), length_cmp);

  for (const std::string& str: vec) {
    std::cout << str << "\n";
  }
}