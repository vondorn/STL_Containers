/* SRTYUIOLIUYTDCVBNJKLOIUYTREWSDCVBNJIOPOIUYTRDFGHNBGDFDFYUFTYDF*/

template <typename Key, typename Value>
AVLTree<Key, Value>::Iterator::Iterator()
    : node_(nullptr), past_node_(nullptr) {}

template <typename Key, typename Value>
AVLTree<Key, Value>::Iterator::Iterator(Node* node, Node* past_node)
    : node_(node), past_node_(past_node) {}

template <typename Key, typename Value>
AVLTree<Key, Value>::Iterator::Iterator(Node* node)
    : node_(node), past_node_(nullptr) {}

template <typename Key, typename Value>
typename AVLTree<Key, Value>::Iterator&
AVLTree<Key, Value>::Iterator::operator++() {
  Node* temp;
  if (node_) {
    temp = getMax(node_);
  }
  node_ = moveForward(node_);
  if (!node_) {
    past_node_ = temp;
  }
  return *this;
}

template <typename Key, typename Value>
typename AVLTree<Key, Value>::Iterator
AVLTree<Key, Value>::Iterator::operator++(int) {
  iterator temp = *this;
  operator++();
  return temp;
}

template <typename Key, typename Value>
typename AVLTree<Key, Value>::Iterator&
AVLTree<Key, Value>::Iterator::operator--() {
  if (!node_ && past_node_) {
    node_ = past_node_;
    return *this;
  }
  node_ = moveBack(node_);
  return *this;
}

template <typename Key, typename Value>
typename AVLTree<Key, Value>::Iterator
AVLTree<Key, Value>::Iterator::operator--(int) {
  Iterator temp = *this;
  operator--();
  return temp;
}

template <typename Key, typename Value>
Value& AVLTree<Key, Value>::Iterator::operator*() {
  if (node_ == nullptr) {
    static Value fake_value{};
    return fake_value;
  }
  return node_->value_;
}

// template <typename Key, typename Value>
// typename AVLTree<Key, Value>::Iterator AVLTree<Key,
// Value>::Iterator::operator+(
//     int n) {
//   for (int i = 0; i < n; i++) {
//     operator++();
//   }
//   return *this;
// }

// template <typename Key, typename Value>
// typename AVLTree<Key, Value>::Iterator AVLTree<Key,
// Value>::Iterator::operator-(
//     int n) {
//   for (int i = 0; i < n; i++) {
//     operator--();
//   }
//   return *this;
// }

template <typename Key, typename Value>
typename AVLTree<Key, Value>::Node* AVLTree<Key, Value>::Iterator::moveForward(
    AVLTree::Node* node) {
  if (node->right_) {
    return getMin(node->right_);
  }
  Node* parent = node->parent_;
  while (parent && node == parent->right_) {
    node = parent;
    parent = parent->parent_;
  }
  return parent;
}

template <typename Key, typename Value>
typename AVLTree<Key, Value>::Node* AVLTree<Key, Value>::Iterator::moveBack(
    AVLTree::Node* node) {
  if (node->left_ != nullptr) {
    return getMax(node->left_);
  }
  Node* parent = node->parent_;
  while (parent != nullptr && node == parent->left_) {
    node = parent;
    parent = node->parent_;
  }
  return parent;
}

template <typename Key, typename Value>
bool AVLTree<Key, Value>::Iterator::operator==(const iterator& it) {
  return node_ == it.node_;
}

template <typename Key, typename Value>
bool AVLTree<Key, Value>::Iterator::operator!=(const iterator& it) {
  return node_ != it.node_;
}