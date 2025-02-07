// Copyright 2024 granceti aka vsem privet and fredgran
#ifndef SRC_S21_CONTAINERSPLUS_S21_MULTISET_MULTISET_H_
#define SRC_S21_CONTAINERSPLUS_S21_MULTISET_MULTISET_H_
#include <algorithm>
#include <limits>
#include <utility>
#include <vector>

// #include "../AVL/avl.h"
namespace s21 {
template <typename Key>
class multiset : public set<Key> {
 public:
  class MultisetIterator;
  // class MultisetConstIterator;

  using value_type = Key;
  using key_type = Key;
  using reference = value_type &;
  using const_reference = const value_type &;
  using iterator = MultisetIterator;
  // using const_iterator = MultisetConstIterator<T>;
  using size_type = size_t;

  multiset() : set<Key>() {}
  multiset(std::initializer_list<value_type> const &items);
  multiset(const multiset &ms) : set<Key>(ms) {}
  multiset(multiset &&ms) : set<Key>(std::move(ms)) {}
  ~multiset() { clear(); }
  multiset &operator=(multiset &&ms) noexcept;

  iterator begin();
  iterator end();

  bool empty() { return set<Key>::empty(); }
  size_type size() { return set<Key>::size(); }
  size_type max_size() { return set<Key>::max_size(); }

  void clear() { return set<Key>::clear(); }
  std::pair<iterator, bool> insert(const value_type &value);
  void erase(iterator pos);
  void swap(multiset &other);
  void merge(multiset &other);

  size_type count(const Key &key);
  iterator find(const Key &key);
  bool contains(const Key &key) { return set<Key>::contains(key); }
  std::pair<iterator, iterator> equal_range(const Key &key);
  iterator lower_bound(const Key &key);
  iterator upper_bound(const Key &key);

  template <typename... Args>
  std::vector<std::pair<iterator, bool>> insert_many(Args &&...args);

  class MultisetIterator : public set<Key>::iterator {
   public:
    MultisetIterator() : set<Key>::iterator() {}
    MultisetIterator(typename AVLTree<Key, Key>::Node *node)
        : set<Key>::iterator(node) {}
    MultisetIterator(typename AVLTree<Key, Key>::Node *node,
                     typename AVLTree<Key, Key>::Node *past_node)
        : set<Key>::iterator(node, past_node) {}

    iterator operator+(int n);
    iterator operator-(int n);
  };
};
}  // namespace s21

#include "multiset.tpp"

#endif  // SRC_S21_CONTAINERSPLUS_S21_MULTISET_MULTISET_H_
