// Copyright 2024 granceti aka vsem privet and fredgran
#ifndef SRC_S21_CONTAINERS_AVL_AVL_H_
#define SRC_S21_CONTAINERS_AVL_AVL_H_
#include <limits>
#include <utility>
#include <vector>

template <typename Key, typename Value>
class AVLTree {
 public:
  class Iterator;
  class ConstIterator;

  using key_type = Key;
  using value_type = Value;
  using reference = value_type&;
  using const_reference = const value_type&;
  using iterator = Iterator;
  using const_iterator = ConstIterator;
  using size_type = size_t;

 public:
  struct Node {
    Node(key_type key, value_type value);
    Node(key_type key, value_type value, Node* parent);
    key_type key_;
    value_type value_;
    Node* left_ = nullptr;
    Node* right_ = nullptr;
    Node* parent_ = nullptr;
    int height_ = 0;
  };

 protected:
  Node* root_;
  AVLTree();
  AVLTree(const AVLTree& other);
  AVLTree(AVLTree&& other) noexcept;
  ~AVLTree();
  AVLTree& operator=(AVLTree&& other) noexcept;
  AVLTree& operator=(const AVLTree& other);

  void freeTree(Node* node);
  Node* copyTree(Node* node, Node* parent);

  int getHeight(Node* node);
  int getBalance(Node* node);
  void setHeight(Node* node);
  bool insert(Node* node, Key key, Value value);
  bool insertMulti(Node* node, Key key, Value value);
  void rightRotate(Node* node);
  void leftRotate(Node* node);
  void balanciaga(Node* node);
  static Node* getMin(Node* node);
  static Node* getMax(Node* node);
  void swapNodes(Node* first, Node* second);
  Node* find(Node* node, Key key);
  Node* findMulti(Node* node, Key key);
  Node* deleteNode(Node* node, Key key);
  size_t size(Node* node);
  size_t max_size();
  Iterator begin();
  Iterator end();
  void erase(iterator pos);
  bool contains(const Key& key);
  bool containsMulti(Node* node, const Key& key);
  bool empty();
  void clear();
  void swap(AVLTree& other);

 public:
  class Iterator {
   public:
    Iterator();
    Iterator(Node* node, Node* past_node);
    Iterator(Node* node);
    iterator& operator++();
    iterator operator++(int);
    iterator& operator--();
    iterator operator--(int);
    reference operator*();
    iterator operator+(int n);
    iterator operator-(int n);
    bool operator!=(const iterator& it);
    bool operator==(const iterator& it);

    friend class AVLTree<Key, Value>;

    Node* node_;
    Node* past_node_;
    Node* moveForward(Node* node);
    Node* moveBack(Node* node);
  };
  class ConstIterator : public Iterator {
   public:
    ConstIterator() : Iterator() {}
    const_reference operator*() const { return Iterator::operator*(); }
  };
};

#include "avl.tpp"
#include "iterators.tpp"

#endif  // SRC_S21_CONTAINERS_AVL_AVL_H_
