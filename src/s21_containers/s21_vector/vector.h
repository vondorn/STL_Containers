// Copyright 2024 granceti aka vsem privet and fredgran
#ifndef SRC_S21_CONTAINERS_S21_VECTOR_VECTOR_H_
#define SRC_S21_CONTAINERS_S21_VECTOR_VECTOR_H_
#include <algorithm>
#include <iostream>
#include <limits>
#include <utility>
namespace s21 {
template <typename T>
class vector {
 public:
  class VectorIterator;
  class VectorConstIterator;

  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator_pointer = T *;
  using const_iterator_pointer = const T *;
  using iterator = vector<T>::VectorIterator;
  using const_iterator = vector<T>::VectorConstIterator;
  using size_type = size_t;

  vector() noexcept;
  vector(size_type n);
  vector(std::initializer_list<value_type> const &items);
  vector(const vector &v);
  vector(vector &&v) noexcept;
  ~vector() noexcept;
  vector &operator=(vector &&v) noexcept;

  iterator begin();
  iterator end();
  const_iterator cbegin() const;
  const_iterator cend() const;

  reference at(size_type pos);
  reference operator[](size_type pos);
  const_reference front() const;
  const_reference back() const;
  iterator_pointer data() noexcept;

  size_type size() const noexcept;
  size_type capacity() const noexcept;
  size_type max_size() const;
  bool empty() const;
  void reserve(size_type size);
  void shrink_to_fit();

  void clear() noexcept;
  void push_back(const_reference value);
  void pop_back();
  void swap(vector<T> &other);
  iterator insert(iterator pos, const_reference value);
  void erase(iterator pos);

  template <typename... Args>
  void insert_many_back(Args &&...args);

  template <typename... Args>
  iterator insert_many(const_iterator pos, Args &&...args);

  void meme(size_type n);

 private:
  iterator_pointer data_;
  size_type size_;
  size_type capacity_;

 public:
  class VectorIterator {
   public:
    VectorIterator();
    VectorIterator(iterator_pointer ptr);

    reference operator*();
    iterator operator++(int);
    iterator operator--(int);
    iterator operator++();
    iterator operator--();
    iterator operator+(int n) const;
    iterator operator-(int n) const;
    bool operator==(const iterator &other) const;
    bool operator!=(const iterator &other) const;
    ptrdiff_t operator-(const iterator &other) const;

   private:
    iterator_pointer ptr_;
  };
  class VectorConstIterator {
   public:
    VectorConstIterator();
    VectorConstIterator(iterator_pointer ptr);

    const_reference operator*();
    const_iterator operator++(int);
    const_iterator operator--(int);
    const_iterator operator++();
    const_iterator operator--();
    const_iterator operator+(int n) const;
    const_iterator operator-(int n) const;
    bool operator==(const const_iterator &other) const;
    bool operator!=(const const_iterator &other) const;
    ptrdiff_t operator-(const const_iterator &other) const;

   private:
    iterator_pointer ptr_;
  };
};
}  // namespace s21

#include "iterators.tpp"
#include "vector.tpp"

#endif  // SRC_S21_CONTAINERS_S21_VECTOR_VECTOR_H_
