// Copyright 2024 granceti aka vsem privet and fredgran
#ifndef SRC_S21_CONTAINERSPLUS_S21_ARRAY_ARRAY_H_
#define SRC_S21_CONTAINERSPLUS_S21_ARRAY_ARRAY_H_
#include <utility>
namespace s21 {
template <typename T, std::size_t N>
class array {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = size_t;

 private:
  value_type arr_[N];
  size_type size_ = N;

 public:
  array();
  array(std::initializer_list<value_type> const &items);
  array(const array &a);
  array(array &&a) noexcept;
  ~array();
  array &operator=(array &&a);
  array &operator=(const array &a);

  reference at(size_type pos);
  reference operator[](size_type pos);
  const_reference at(size_type pos) const;
  const_reference operator[](size_type pos) const;
  const_reference front();
  const_reference back();
  iterator data();

  iterator begin();
  iterator end();

  bool empty();
  size_type size();
  size_type max_size();

  void swap(array &other);
  void fill(const_reference value);
};
}  // namespace s21

#include "array.tpp"

#endif  // SRC_S21_CONTAINERSPLUS_S21_ARRAY_ARRAY_H_
