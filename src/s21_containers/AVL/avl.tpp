
template <typename Key, typename Value>
AVLTree<Key, Value>::AVLTree() : root_(nullptr) {}

template <typename Key, typename Value>
AVLTree<Key, Value>::AVLTree(const AVLTree& other) {
  root_ = copyTree(other.root_, nullptr);
}

template <typename Key, typename Value>
AVLTree<Key, Value>::AVLTree(AVLTree&& other) noexcept {
  root_ = other.root_;
  other.root_ = nullptr;
}

template <typename Key, typename Value>
AVLTree<Key, Value>::~AVLTree() {
  clear();
}

template <typename Key, typename Value>
AVLTree<Key, Value>& AVLTree<Key, Value>::operator=(AVLTree&& other) noexcept {
  if (this != &other) {
    root_ = other.root_;
    other.root_ = nullptr;
  }
  return *this;
}

template <typename Key, typename Value>
AVLTree<Key, Value>& AVLTree<Key, Value>::operator=(const AVLTree& other) {
  if (this != &other) {
    clear();
    AVLTree temp(other);
    *this = std::move(temp);
  }
  return *this;
}

template <typename Key, typename Value>
typename AVLTree<Key, Value>::Node* AVLTree<Key, Value>::copyTree(
    Node* node, Node* parent) {
  if (!node) return nullptr;
  Node* new_node = new Node(node->key_, node->value_, parent);
  new_node->left_ = copyTree(node->left_, new_node);
  new_node->right_ = copyTree(node->right_, new_node);
  return new_node;
}

template <typename Key, typename Value>
void AVLTree<Key, Value>::freeTree(Node* node) {
  if (node == nullptr) {
    return;
  }
  freeTree(node->left_);
  freeTree(node->right_);
  delete node;
}

template <typename Key, typename Value>
AVLTree<Key, Value>::Node::Node(key_type key, value_type value)
    : key_(key), value_(value) {}

template <typename Key, typename Value>
AVLTree<Key, Value>::Node::Node(key_type key, value_type value, Node* parent)
    : key_(key), value_(value), parent_(parent) {}

template <typename Key, typename Value>
int AVLTree<Key, Value>::getHeight(Node* node) {
  return node != nullptr ? node->height_ : -1;
}

template <typename Key, typename Value>
int AVLTree<Key, Value>::getBalance(Node* node) {
  return node != nullptr ? getHeight(node->right_) - getHeight(node->left_) : 0;
}

template <typename Key, typename Value>
void AVLTree<Key, Value>::setHeight(Node* node) {
  node->height_ = std::max(getHeight(node->left_), getHeight(node->right_)) + 1;
}

template <typename Key, typename Value>
bool AVLTree<Key, Value>::insert(Node* node, Key key, Value value) {
  bool flag = 1;
  if (key < node->key_) {
    if (!node->left_) {
      node->left_ = new Node(key, value, node);
    } else {
      flag = insert(node->left_, key, value);
    }
  } else if (key > node->key_) {
    if (!node->right_) {
      node->right_ = new Node(key, value, node);
    } else {
      flag = insert(node->right_, key, value);
    }
  } else {
    flag = 0;
  }
  setHeight(node);
  balanciaga(node);
  return flag;
}

template <typename Key, typename Value>
void AVLTree<Key, Value>::rightRotate(Node* node) {
  swapNodes(node, node->left_);
  Node* temp_right = node->right_;
  node->right_ = node->left_;
  node->left_ = node->right_->left_;
  node->right_->left_ = node->right_->right_;
  node->right_->right_ = temp_right;
  if (node->left_) {
    node->left_->parent_ = node;
  }
  if (node->right_->right_) {
    node->right_->right_->parent_ = node->right_;
  }
  setHeight(node->right_);
  setHeight(node);
}

template <typename Key, typename Value>
void AVLTree<Key, Value>::leftRotate(Node* node) {
  swapNodes(node, node->right_);
  Node* temp_left = node->left_;
  node->left_ = node->right_;
  node->right_ = node->left_->right_;
  node->left_->right_ = node->left_->left_;
  node->left_->left_ = temp_left;
  if (node->right_) {
    node->right_->parent_ = node;
  }
  if (node->left_->left_) {
    node->left_->left_->parent_ = node->left_;
  }
  setHeight(node->left_);
  setHeight(node);
}

template <typename Key, typename Value>
void AVLTree<Key, Value>::balanciaga(Node* node) {
  short int balance = getBalance(node);
  if (balance == -2) {
    if (getBalance(node->left_) == 1) {
      leftRotate(node->left_);
    }
    rightRotate(node);
  } else if (balance == 2) {
    if (getBalance(node->right_) == -1) {
      rightRotate(node->right_);
    }
    leftRotate(node);
  }
}

template <typename Key, typename Value>
typename AVLTree<Key, Value>::Node* AVLTree<Key, Value>::getMin(Node* node) {
  if (!node) {
    return nullptr;
  }
  if (!node->left_) {
    return node;
  }
  return getMin(node->left_);
}

template <typename Key, typename Value>
typename AVLTree<Key, Value>::Node* AVLTree<Key, Value>::getMax(Node* node) {
  if (!node) {
    return nullptr;
  }
  if (!node->right_) {
    return node;
  }
  return getMax(node->right_);
}

template <typename Key, typename Value>
void AVLTree<Key, Value>::swapNodes(Node* first, Node* second) {
  std::swap(first->key_, second->key_);
  std::swap(first->value_, second->value_);
}

template <typename Key, typename Value>
typename AVLTree<Key, Value>::Node* AVLTree<Key, Value>::find(Node* node,
                                                              Key key) {
  if (!node || key == node->key_) {
    return node;
  } else if (key < node->key_) {
    return find(node->left_, key);
  } else {
    return find(node->right_, key);
  }
}

template <typename Key, typename Value>
typename AVLTree<Key, Value>::Node* AVLTree<Key, Value>::findMulti(Node* node,
                                                                   Key key) {
  if (!node || key == node->key_) {
    if (node) {
      while (containsMulti(node->left_, key) && node->left_) {
        node = node->left_;
      }
      return node;
    }
    return node;
  } else if (key < node->key_) {
    return findMulti(node->left_, key);
  } else {
    return findMulti(node->right_, key);
  }
}

template <typename Key, typename Value>
size_t AVLTree<Key, Value>::size(Node* node) {
  if (!node) return 0;
  return 1 + size(node->left_) + size(node->right_);
}

template <typename Key, typename Value>
typename AVLTree<Key, Value>::Iterator AVLTree<Key, Value>::begin() {
  return iterator(getMin(root_), nullptr);
}

template <typename Key, typename Value>
typename AVLTree<Key, Value>::Iterator AVLTree<Key, Value>::end() {
  return iterator(nullptr, getMax(root_));
}

template <typename Key, typename Value>
typename AVLTree<Key, Value>::Node* AVLTree<Key, Value>::deleteNode(Node* node,
                                                                    Key key) {
  if (!node) {
    return nullptr;
  }
  if (key < node->key_) {
    node->left_ = deleteNode(node->left_, key);
  } else if (key > node->key_) {
    node->right_ = deleteNode(node->right_, key);
  } else {
    if (!node->left_ || !node->right_) {
      Node* temp = (node->left_) ? node->left_ : node->right_;
      delete node;
      node = temp;
    } else {
      Node* maxInLeft = getMax(node->left_);
      node->key_ = maxInLeft->key_;
      node->value_ = maxInLeft->value_;
      node->left_ = deleteNode(node->left_, maxInLeft->key_);
    }
  }
  if (node) {
    setHeight(node);
    balanciaga(node);
  }
  return node;
}

template <typename Key, typename Value>
bool AVLTree<Key, Value>::contains(const Key& key) {
  Node* contain_node = find(root_, key);
  return contain_node;
}

template <typename Key, typename Value>
bool AVLTree<Key, Value>::containsMulti(Node* node, const Key& key) {
  return find(node, key);
}

template <typename Key, typename Value>
bool AVLTree<Key, Value>::empty() {
  return !root_;
}

template <typename Key, typename Value>
size_t AVLTree<Key, Value>::max_size() {
  return std::numeric_limits<size_type>::max() /
         sizeof(typename AVLTree<Key, Value>::Node);
}

template <typename Key, typename Value>
void AVLTree<Key, Value>::clear() {
  if (root_ != nullptr) {
    freeTree(root_);
    root_ = nullptr;
  }
}

template <typename Key, typename Value>
void AVLTree<Key, Value>::swap(AVLTree& other) {
  std::swap(root_, other.root_);
}

template <typename Key, typename Value>
bool AVLTree<Key, Value>::insertMulti(Node* node, Key key, Value value) {
  bool flag = 1;
  if (key < node->key_) {
    if (!node->left_) {
      node->left_ = new Node(key, value, node);
    } else {
      flag = insertMulti(node->left_, key, value);
    }
  } else {
    if (!node->right_) {
      node->right_ = new Node(key, value, node);
    } else {
      flag = insertMulti(node->right_, key, value);
    }
  }
  setHeight(node);
  balanciaga(node);
  return flag;
}