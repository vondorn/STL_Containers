// Copyright 2024 granceti aka vsem privet and fredgran
#ifndef SRC_S21_CONTAINERS_S21_LIST_LIST_H_
#define SRC_S21_CONTAINERS_S21_LIST_LIST_H_
#include <limits>
#include <utility>
namespace s21 {
template <typename T>
class list {
 public:
  class ListIterator;
  class ListConstIterator;
  using value_type = T;
  using reference = T&;
  using const_reference = const T&;
  using iterator = list<T>::ListIterator;
  using const_iterator = list<T>::ListConstIterator;
  using size_type = size_t;

 private:
  struct Node {
    value_type value_;
    Node* prev_;
    Node* next_;

    Node(const value_type& value)
        : value_(value), prev_(nullptr), next_(nullptr) {}
  };

  Node* head_;
  Node* tail_;
  size_type size_;

  Node* mergeSort(Node* head);
  Node* mergeNode(Node* left, Node* right);

 public:
  class ListIterator {
   public:
    ListIterator();
    ListIterator(Node* node);
    ListIterator(Node* node, Node* tail);
    ListIterator(const const_iterator& const_it) : node_(const_it.node_) {}

    reference operator*();
    iterator& operator++();
    iterator& operator--();
    iterator operator++(int);
    iterator operator--(int);
    iterator operator+(int n) const;
    iterator operator-(int n) const;
    bool operator==(const iterator& other) const;
    bool operator!=(const iterator& other) const;
    Node get_node() const noexcept;

   private:
    friend class list<T>;
    Node* node_;
    Node* tail_;
  };

  class ListConstIterator {
   public:
    ListConstIterator();
    ListConstIterator(const Node* node);
    ListConstIterator(const iterator& it);

    const_reference operator*();
    const_iterator& operator++();
    const_iterator& operator--();
    const_iterator operator++(int);
    const_iterator operator--(int);

    bool operator==(const const_iterator& it) const;
    bool operator!=(const const_iterator& it) const;
    Node get_node() const noexcept;

   private:
    friend class list<T>;
    friend class ListIterator;
    Node* node_;
  };

  list();
  list(size_type n);
  list(std::initializer_list<value_type> const& items);
  list(const list& l);
  list(list&& l);
  ~list() noexcept;
  list& operator=(list&& l);
  list& operator=(const list& other);

  const_reference front() const;
  const_reference back() const;

  iterator begin() noexcept;
  // const_iterator begin() const noexcept;
  // const_iterator cbegin() const noexcept;
  iterator end() noexcept;
  // const_iterator end() const noexcept;
  // const_iterator cend() const noexcept;

  bool empty() const noexcept;
  size_type size() const noexcept;
  size_type max_size() const noexcept;

  void clear() noexcept;
  iterator insert(iterator pos, const_reference value);
  void erase(iterator pos);
  void push_back(const_reference value);
  void pop_back();
  void push_front(const_reference value);
  void pop_front();
  void swap(list& other);
  void merge(list& other);
  void splice(const_iterator pos, list& other);
  void reverse();
  void unique();
  void sort();
  // void resize(size_type count);

  template <typename... Args>
  iterator insert_many(const_iterator pos, Args&&... args);
  template <typename... Args>
  void insert_many_back(Args&&... args);
  template <typename... Args>
  void insert_many_front(Args&&... args);
};
}  // namespace s21

#include "iterator.tpp"
#include "list.tpp"

#endif  // SRC_S21_CONTAINERS_S21_LIST_LIST_H_
