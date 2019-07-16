#ifndef STRINGQUEUE_H_
#define STRINGQUEUE_H_

#include <string>
#include <memory>
#include <iterator>

template <typename T, int Size>
class GenericQueue {
  static constexpr int TRUE_SIZE = Size + 1;

 public:
  GenericQueue() : head_{0}, tail_{0}, queue_{ } {};
  
  void enque(T s);
  T deque();
  int size() const;

 private:
  int head_;
  int tail_;
  std::array<T, TRUE_SIZE> queue_;
};

template <typename T, int Size>
void GenericQueue<T, Size>::enque(T s) {
  if((head_ + 1) % TRUE_SIZE == tail_) {
    throw std::runtime_error("queue is full");
  }
  queue_[head_++] = s;
}

template <typename T, int Size>
T GenericQueue<T, Size>::deque() {
  T ret_str = queue_[tail_++];
  return ret_str;
}

template <typename T, int Size>
int GenericQueue<T, Size>::size() const {
  if (head_ < tail_) {
    return TRUE_SIZE + tail_ - head_;
  } else {
    return head_ - tail_;
  }
}

#endif  // STRINGQUEUE_H_