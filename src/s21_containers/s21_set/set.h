// Copyright 2024 granceti aka vsem privet and fredgran
#ifndef SRC_S21_CONTAINERS_S21_SET_SET_H_
#define SRC_S21_CONTAINERS_S21_SET_SET_H_
#include <algorithm>
#include <limits>
#include <utility>
#include <vector>

namespace s21 {
template <typename Key>
class set : public AVLTree<Key, Key> {
 public:
  class SetIterator;
  //   class SetConstIterator;

  using value_type = Key;
  using key_type = Key;
  using reference = value_type &;
  using const_reference = const value_type &;
  using iterator = SetIterator;
  //   using const_iterator = SetConstIterator;
  using size_type = size_t;

  set() : AVLTree<Key, Key>() {}
  set(std::initializer_list<value_type> const &items);
  set(const set &other) : AVLTree<Key, Key>(other) {}
  set(set &&other) noexcept : AVLTree<Key, Key>(std::move(other)) {}
  set &operator=(set &&other) noexcept;
  set &operator=(const set &other);
  ~set() { clear(); }

  iterator begin();
  iterator end();

  bool empty();
  size_type size();
  size_type max_size();

  void clear();
  std::pair<iterator, bool> insert(const value_type &value);
  void erase(iterator pos);
  void swap(set &other);
  void merge(set &other);

  iterator find(const Key &key);
  bool contains(const Key &key);

  template <typename... Args>
  std::vector<std::pair<iterator, bool>> insert_many(Args &&...args);

  class SetIterator : public AVLTree<Key, Key>::Iterator {
   public:
    SetIterator() : AVLTree<Key, Key>::Iterator() {}
    SetIterator(typename AVLTree<Key, Key>::Node *node)
        : AVLTree<Key, Key>::Iterator(node) {}
    SetIterator(typename AVLTree<Key, Key>::Node *node,
                typename AVLTree<Key, Key>::Node *past_node)
        : AVLTree<Key, Key>::Iterator(node, past_node) {}
  };
};
}  // namespace s21

#include "set.tpp"

#endif  // SRC_S21_CONTAINERS_S21_SET_SET_H_
