// Copyright 2024 granceti aka vsem privet and fredgran
#ifndef SRC_S21_CONTAINERS_S21_STACK_STACK_H_
#define SRC_S21_CONTAINERS_S21_STACK_STACK_H_
#include <utility>
namespace s21 {
template <typename T>
class stack {
 public:
  using value_type = T;
  using reference = T&;
  using const_reference = const T&;
  using size_type = size_t;

 private:
  struct Node {
    value_type value_;
    Node* next_;

    Node(const value_type& value) : value_(value), next_(nullptr) {}
  };

  Node* top_;
  size_type size_;

 public:
  stack();
  stack(std::initializer_list<value_type> const& items);
  stack(const stack& s);
  stack(stack&& s);
  ~stack() noexcept;
  stack& operator=(stack&& s);
  stack& operator=(const stack& other);

  const_reference top() const;

  bool empty();
  size_type size();

  void push(const_reference value);
  void pop();
  void swap(stack& other);

  template <typename... Args>
  void insert_many_back(Args&&... args);
};
}  // namespace s21

#include "stack.tpp"

#endif  // SRC_S21_CONTAINERS_S21_STACK_STACK_H_
