#ifndef _S21QUEUE_H_
#define _S21QUEUE_H_

#include <deque>

namespace s21 {
template <typename T, typename Container = std::deque<T>>
class queue {
 public:
  queue() {}

  void push(T value) { cont_.push_back(value); }

  void pop() { cont_.pop_front(); }

  T front() { return cont_.front(); }

  T back() { return cont_.back(); }

  bool empty() { return cont_.empty(); }

 private:
  Container cont_;
};
}  // namespace s21

#endif  // _S21QUEUE_H_
