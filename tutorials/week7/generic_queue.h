#ifndef STRINGQUEUE_H_
#define STRINGQUEUE_H_

#include <string>
#include <memory>
#include <iterator>

template <typename T>
class GenericQueue {
 public:
  GenericQueue(int size) : size_curr_{0}, size_max_{size}, queue_{std::make_unique<T[]>(size)} {};
  void enque(T s);
  T deque();
  int size() const;

 private:
  int size_curr_;
  int size_max_;
  std::unique_ptr<T[]> queue_;
};

template <typename T>
void GenericQueue<T>::enque(T s) {
  if(size_curr_ >= size_max_) {
    throw std::runtime_error("queue is full");
  }
  queue_[size_curr_++] = s;
}

template <typename T>
T GenericQueue<T>::deque() {
  T ret_str = queue_[0];
  auto from = std::next(queue_.get());
  auto to   = queue_.get() + size();
  std::move(from, to, queue_.get());
  --size_curr_;
  return ret_str;
}

template <typename T>
int GenericQueue<T>::size() const {
  return size_curr_;
}

#endif  // STRINGQUEUE_H_