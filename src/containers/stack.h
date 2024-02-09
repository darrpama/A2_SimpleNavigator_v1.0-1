#ifndef _S21STACK_H_
#define _S21STACK_H_

#include <deque>

namespace s21 {
    template<typename T, typename Container = std::deque<T>>
    class stack {
       public:
        stack() {}
        
        void push(T value) {
            cont_.push_front(value);
        }

        void pop() {
            cont_.pop_front();
        }

        T top() {
            return cont_.front();
        }

        bool empty() {
            return cont_.empty();
        }
    
       private:
        Container cont_;
    };
} // namespace s21


#endif  // _S21STACK_H_
