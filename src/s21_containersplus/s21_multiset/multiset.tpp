
namespace s21 {
template <typename Key>
multiset<Key>::multiset(const std::initializer_list<value_type>& items) {
  for (auto it = items.begin(); it != items.end(); ++it) {
    insert(*it);
  }
}

template <typename Key>
multiset<Key>& multiset<Key>::operator=(multiset&& ms) noexcept {
  if (this != &ms) {
    set<Key>::operator=(std::move(ms));
  }
  return *this;
}

template <typename Key>
typename multiset<Key>::iterator multiset<Key>::begin() {
  return multiset<Key>::MultisetIterator(
      AVLTree<Key, Key>::getMin(AVLTree<Key, Key>::root_));
}

template <typename Key>
typename multiset<Key>::iterator multiset<Key>::end() {
  if (!AVLTree<Key, Key>::root_) return begin();
  return multiset<Key>::MultisetIterator(
      nullptr, AVLTree<Key, Key>::getMax(AVLTree<Key, Key>::root_));
}

template <typename Key>
std::pair<typename multiset<Key>::iterator, bool> multiset<Key>::insert(
    const value_type& value) {
  std::pair<iterator, bool> return_value;
  bool flag = 1;
  if (!AVLTree<Key, Key>::root_) {
    AVLTree<Key, Key>::root_ =
        new typename AVLTree<Key, Key>::Node(value, value);
    return_value.first = iterator(AVLTree<Key, Key>::root_);
  } else {
    flag =
        AVLTree<Key, Key>::insertMulti(AVLTree<Key, Key>::root_, value, value);
    return_value.first =
        AVLTree<Key, Key>::find(AVLTree<Key, Key>::root_, value);
  }
  return_value.second = flag;
  return return_value;
}

template <typename Key>
void multiset<Key>::erase(iterator pos) {
  if (AVLTree<Key, Key>::root_ && pos.node_) {
    // size_t keys = count(pos.node_->key_);
    AVLTree<Key, Key>::root_ = AVLTree<Key, Key>::deleteNode(
        AVLTree<Key, Key>::root_, pos.node_->key_);
    // while (--keys) {
    // 	insert(pos.node_->key_);
    // }
  }
}

template <typename Key>
void multiset<Key>::swap(multiset& other) {
  AVLTree<Key, Key>::swap(other);
}

template <typename Key>
void multiset<Key>::merge(multiset& other) {
  multiset const_tree(other);
  iterator const_it = const_tree.begin();
  for (; const_it != const_tree.end(); const_it++) {
    std::pair<iterator, bool> pr = insert(*const_it);
    if (pr.second) {
      other.erase(pr.first);
    }
  }
}

template <typename Key>
typename multiset<Key>::iterator multiset<Key>::find(const Key& key) {
  typename AVLTree<Key, Key>::Node* node =
      AVLTree<Key, Key>::findMulti(AVLTree<Key, Key>::root_, key);
  iterator return_value(node);
  if (!node) {
    *return_value = size();
  }
  return return_value;
}

template <typename Key>
size_t multiset<Key>::count(const Key& key) {
  size_t counter = 0;
  if (contains(key)) {
    iterator it = begin();
    while (it != end()) {
      if (*it == key) counter++;
      it++;
    }
  }
  return counter;
}

template <typename Key>
std::pair<typename multiset<Key>::iterator, typename multiset<Key>::iterator>
multiset<Key>::equal_range(const Key& key) {
  return std::make_pair(lower_bound(key), upper_bound(key));
}

template <typename Key>
typename multiset<Key>::iterator multiset<Key>::lower_bound(const Key& key) {
  return find(key);
}

template <typename Key>
typename multiset<Key>::iterator multiset<Key>::upper_bound(const Key& key) {
  return find(key) + count(key);
}

template <typename Key>
typename multiset<Key>::iterator multiset<Key>::iterator::operator+(int n) {
  for (int i = 0; i < n; i++) {
    AVLTree<Key, Key>::Iterator::operator++();
  }
  return *this;
}

template <typename Key>
typename multiset<Key>::iterator multiset<Key>::iterator::operator-(int n) {
  for (int i = 0; i < n; i++) {
    AVLTree<Key, Key>::Iterator::operator--();
  }
  return *this;
}

template <typename Key>
template <typename... Args>
std::vector<std::pair<typename multiset<Key>::iterator, bool>>
multiset<Key>::insert_many(Args&&... args) {
  std::vector<std::pair<iterator, bool>> return_value;
  for (const auto& arg : {args...}) {
    return_value.push_back(insert(arg));
  }
  return return_value;
}

}  // namespace s21