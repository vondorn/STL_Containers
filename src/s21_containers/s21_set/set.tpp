
#include <vector>

namespace s21 {
template <typename Key>
set<Key>::set(const std::initializer_list<value_type>& items) {
  for (auto it = items.begin(); it != items.end(); ++it) {
    insert(*it);
  }
}

template <typename Key>
set<Key>& set<Key>::operator=(set&& other) noexcept {
  if (this != &other) {
    AVLTree<Key, Key>::operator=(std::move(other));
  }
  return *this;
}

template <typename Key>
set<Key>& set<Key>::operator=(const set& other) {
  if (this != &other) {
    AVLTree<Key, Key>::operator=(other);
  }
  return *this;
}

template <typename Key>
typename set<Key>::iterator set<Key>::begin() {
  return set<Key>::SetIterator(
      AVLTree<Key, Key>::getMin(AVLTree<Key, Key>::root_));
}

template <typename Key>
typename set<Key>::iterator set<Key>::end() {
  if (!AVLTree<Key, Key>::root_) return begin();
  return set<Key>::SetIterator(
      nullptr, AVLTree<Key, Key>::getMax(AVLTree<Key, Key>::root_));
}

template <typename Key>
bool set<Key>::empty() {
  return AVLTree<Key, Key>::empty();
}

template <typename Key>
size_t set<Key>::size() {
  return AVLTree<Key, Key>::size(AVLTree<Key, Key>::root_);
}

template <typename Key>
size_t set<Key>::max_size() {
  return AVLTree<Key, Key>::max_size();
}

template <typename Key>
void set<Key>::clear() {
  AVLTree<Key, Key>::clear();
}

template <typename Key>
std::pair<typename set<Key>::iterator, bool> set<Key>::insert(
    const value_type& value) {
  std::pair<iterator, bool> return_value;
  bool flag = 1;
  if (!AVLTree<Key, Key>::root_) {
    AVLTree<Key, Key>::root_ =
        new typename AVLTree<Key, Key>::Node(value, value);
    return_value.first = iterator(AVLTree<Key, Key>::root_);
  } else {
    flag = AVLTree<Key, Key>::insert(AVLTree<Key, Key>::root_, value, value);
    return_value.first =
        AVLTree<Key, Key>::find(AVLTree<Key, Key>::root_, value);
  }
  return_value.second = flag;
  return return_value;
}

template <typename Key>
void set<Key>::erase(iterator pos) {
  if (AVLTree<Key, Key>::root_ && pos.node_) {
    AVLTree<Key, Key>::root_ = AVLTree<Key, Key>::deleteNode(
        AVLTree<Key, Key>::root_, pos.node_->key_);
  }
}

template <typename Key>
void set<Key>::swap(set& other) {
  AVLTree<Key, Key>::swap(other);
}

template <typename Key>
void set<Key>::merge(set& other) {
  set const_tree(other);
  iterator const_it = const_tree.begin();
  for (; const_it != const_tree.end(); const_it++) {
    std::pair<iterator, bool> pr = insert(*const_it);
    if (pr.second) {
      other.erase(pr.first);
    }
  }
}

template <typename Key>
bool set<Key>::contains(const Key& key) {
  return AVLTree<Key, Key>::contains(key);
}

template <typename Key>
typename set<Key>::iterator set<Key>::find(const Key& key) {
  typename AVLTree<Key, Key>::Node* node =
      AVLTree<Key, Key>::find(AVLTree<Key, Key>::root_, key);
  iterator return_value(node);
  if (!node) {
    *return_value = size();
  }
  return return_value;
}

template <typename Key>
template <typename... Args>
std::vector<std::pair<typename set<Key>::iterator, bool>> set<Key>::insert_many(
    Args&&... args) {
  std::vector<std::pair<iterator, bool>> return_value;
  for (const auto& arg : {args...}) {
    return_value.push_back(insert(arg));
  }
  return return_value;
}

}  // namespace s21