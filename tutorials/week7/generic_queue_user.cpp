#include <vector>
#include <assert.h>
#include <iostream>
#include "tutorials/week7/generic_queue.h"

int main() {
  GenericQueue<int, 5> my_queue{ };
  std::vector<int>  integers{ 6, 9, 69, 1337, 9001 };
  std::vector<int>  repeated_integers{ };

  for (int integer: integers) {
    my_queue.enque(integer);
  }

  assert(my_queue.size() == static_cast<int>(integers.size()));

  for (int integer: integers) {
    if (my_queue.deque() == integer) {
      std::cout << "good stuff\n";
    }
    else {
      std::cout << "not good stuff\n";
    }
  }

  assert(my_queue.size() == 0);
}