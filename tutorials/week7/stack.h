#ifndef LECTURES_WEEK7_STACK_H_
#define LECTURES_WEEK7_STACK_H_

#include <vector>

template <typename T>
class Stack {
 public:
  void push(T);
  T pop();
 private:
  std::vector<T> stack_;
};

template <typename T>
void Stack<T>::push(T t) {
  stack_.push_back(t);
}

template <typename T>
T Stack<T>::pop() {
  T ret_val = stack_.back();
  stack_.pop_back();
  return ret_val;
}

#endif  // LECTURES_WEEK7_STACK_H_
