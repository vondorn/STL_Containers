// Copyright 2024 granceti aka vsem privet and fredgran
#ifndef SRC_S21_CONTAINERS_S21_MAP_MAP_H_
#define SRC_S21_CONTAINERS_S21_MAP_MAP_H_
#include "./../AVL/avl.h"

namespace s21 {
template <typename Key, typename T>
class map : public AVLTree<Key, T> {
 public:
  class MapIterator;
  class ConstMapIterator;

  using key_type = Key;
  using mapped_type = T;
  using value_type = std::pair<const key_type, mapped_type>;
  using reference = value_type&;
  using const_reference = const value_type&;
  using iterator = MapIterator;
  using const_iterator = ConstMapIterator;
  using size_type = size_t;

  map() : AVLTree<Key, T>() {}
  map(std::initializer_list<value_type> const& items);
  map(const map& other) : AVLTree<Key, T>(other) {}
  map(map&& other) noexcept : AVLTree<Key, T>(std::move(other)) {}
  map& operator=(map&& other) noexcept;
  map& operator=(const map& other);
  ~map() { clear(); }

  T& at(const Key& key);
  T& operator[](const Key& key);

  iterator begin();
  iterator end();

  bool empty();
  size_type size();
  size_type max_size();

  void clear();
  std::pair<iterator, bool> insert(const value_type& value);
  std::pair<iterator, bool> insert(const Key& key, const T& obj);
  std::pair<iterator, bool> insert_or_assign(const Key& key, const T& obj);
  void erase(iterator pos);
  void swap(map& other);
  void merge(map& other);

  bool contains(const Key& key);
  iterator find(const Key& key);

  template <typename... Args>
  std::vector<std::pair<iterator, bool>> insert_many(Args&&... args);

  class MapIterator : public AVLTree<Key, T>::Iterator {
   public:
    MapIterator() : AVLTree<Key, T>::Iterator() {}
    MapIterator(typename AVLTree<Key, T>::Node* node)
        : AVLTree<Key, T>::Iterator(node) {}
    MapIterator(typename AVLTree<Key, T>::Node* node,
                typename AVLTree<Key, T>::Node* past_node)
        : AVLTree<Key, T>::Iterator(node, past_node) {}
    value_type operator*();
    friend class map;

   private:
    T& return_value();
  };

  class ConstMapIterator : public MapIterator {
   public:
    ConstMapIterator() : MapIterator() {}
    ConstMapIterator(typename AVLTree<Key, T>::Node* node)
        : AVLTree<Key, T>::Iterator(node) {}
    ConstMapIterator(typename AVLTree<Key, T>::Node* node,
                     typename AVLTree<Key, T>::Node* past_node)
        : MapIterator(node, past_node) {}
    value_type operator*() const { return MapIterator::operator*(); }
    friend class map;
  };
};

}  // namespace s21

#include "iterators.tpp"
#include "map.tpp"

#endif  // SRC_S21_CONTAINERS_S21_MAP_MAP_H_
