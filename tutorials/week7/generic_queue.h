#ifndef STRINGQUEUE_H_
#define STRINGQUEUE_H_

#include <string>
#include <memory>
#include <iterator>

template <typename T, std::size_t Size>
class GenericQueue {
 public:
  GenericQueue() : size_curr_{0}, queue_{ } {};
  
  void enque(T s);
  T deque();
  int size() const;

 private:
  int size_curr_;
  std::array<T, Size> queue_;
};

template <typename T, std::size_t Size>
void GenericQueue<T, Size>::enque(T s) {
  if(size_curr_ >= static_cast<int>(Size)) {
    throw std::runtime_error("queue is full");
  }
  queue_[size_curr_++] = s;
}

template <typename T, std::size_t Size>
T GenericQueue<T, Size>::deque() {
  T ret_str = queue_[0];
  auto from = std::next(queue_.begin());
  auto to   = std::end(queue_);
  std::move(from, to, queue_.begin());
  --size_curr_;
  return ret_str;
}

template <typename T, std::size_t Size>
int GenericQueue<T, Size>::size() const {
  return size_curr_;
}

#endif  // STRINGQUEUE_H_