#ifndef STRINGQUEUE_H_
#define STRINGQUEUE_H_

#include <string>
#include <memory>
#include <iterator>

class StringQueue {
 public:
  StringQueue(int size) : size_curr_{0}, size_max_{size}, queue_{std::make_unique<std::string[]>(size)} {}
  void enque(std::string s);
  std::string deque();
  int size() const;

 private:
  int size_curr_;
  int size_max_;
  std::unique_ptr<std::string[]> queue_;
};

void StringQueue::enque(std::string s) {
  if(size_curr_ >= size_max_) {
    throw std::runtime_error("queue is full");
  }
  queue_[size_curr_++] = s;
}

std::string StringQueue::deque() {
  std::string ret_str = queue_[0];
  auto from = std::next(queue_.get());
  auto to   = queue_.get() + size();
  std::move(from, to, queue_.get());
  --size_curr_;
  return ret_str;
}

int StringQueue::size() const {
  return size_curr_;
}

#endif  // STRINGQUEUE_H_