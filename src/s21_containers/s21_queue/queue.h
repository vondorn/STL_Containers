// Copyright 2024 granceti aka vsem privet and fredgran
#ifndef SRC_S21_CONTAINERS_S21_QUEUE_QUEUE_H_
#define SRC_S21_CONTAINERS_S21_QUEUE_QUEUE_H_
#include <utility>
namespace s21 {
template <typename T>
class queue {
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

  Node* head_;
  Node* tail_;
  size_type size_;

 public:
  queue();
  queue(std::initializer_list<value_type> const& items);
  queue(const queue& q);
  queue(queue&& q);
  ~queue() noexcept;
  queue& operator=(queue&& q);
  queue& operator=(const queue& other);

  const_reference front() const;
  const_reference back() const;

  bool empty() const noexcept;
  size_type size() const noexcept;

  void push(const_reference value);
  void pop();
  void swap(queue& other);

  template <typename... Args>
  void insert_many_back(Args&&... args);
};
}  // namespace s21

#include "queue.tpp"

#endif  // SRC_S21_CONTAINERS_S21_QUEUE_QUEUE_H_
