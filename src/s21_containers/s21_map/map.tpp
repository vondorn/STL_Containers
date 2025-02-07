

namespace s21 {

/* MAP MEMBER FUNCTIONS MAP MEMBER FUNCTIONS MAP MEMBER FUNCTIONS */

template <typename Key, typename T>
map<Key, T>::map(const std::initializer_list<value_type>& items) {
  for (auto it = items.begin(); it != items.end(); ++it) {
    insert(*it);
  }
}

template <typename Key, typename T>
map<Key, T>& map<Key, T>::operator=(map&& other) noexcept {
  if (this != &other) {
    AVLTree<Key, T>::operator=(std::move(other));
  }
  return *this;
}

template <typename Key, typename T>
map<Key, T>& map<Key, T>::operator=(const map& other) {
  if (this != &other) {
    AVLTree<Key, T>::operator=(other);
  }
  return *this;
}

/* MAP ELEMENT ACCESS MAP ELEMENT ACCESS MAP ELEMENT ACCESS  */

template <typename Key, typename T>
T& map<Key, T>::at(const Key& key) {
  auto it = find(key);
  if (it == nullptr) {
    throw std::out_of_range("ERROR");  // real error text must be
  }
  return it.return_value();
}

template <typename Key, typename T>
T& map<Key, T>::operator[](const Key& key) {
  auto it = find(key);
  if (it == nullptr) {
    auto pr = insert(std::make_pair(key, T()));
    it = pr.first;
  }
  return it.return_value();
}

/* MAP ITERATORS MAP ITERATORS MAP ITERATORS MAP ITERATORS */

template <typename Key, typename T>
typename map<Key, T>::iterator map<Key, T>::begin() {
  return map<Key, T>::MapIterator(
      AVLTree<Key, T>::getMin(AVLTree<Key, T>::root_));
}

template <typename Key, typename T>
typename map<Key, T>::iterator map<Key, T>::end() {
  if (!AVLTree<Key, T>::root_) return begin();
  return map<Key, T>::MapIterator(
      nullptr, AVLTree<Key, T>::getMax(AVLTree<Key, T>::root_));
}

/* MAP CAPACITY MAP CAPACITY MAP CAPACITY MAP CAPACITY MAP CAPACITY */

template <typename Key, typename T>
bool map<Key, T>::empty() {
  return AVLTree<Key, T>::empty();
}

template <typename Key, typename T>
size_t map<Key, T>::size() {
  return AVLTree<Key, T>::size(AVLTree<Key, T>::root_);
}

template <typename Key, typename T>
size_t map<Key, T>::max_size() {
  return AVLTree<Key, T>::max_size();
}

/* MAP MODIFIERS MAP MODIFIERS MAP MODIFIERS MAP MODIFIERS MAP MODIFIERS */

template <typename Key, typename T>
void map<Key, T>::clear() {
  AVLTree<Key, T>::clear();
}

template <typename Key, typename T>
std::pair<typename map<Key, T>::iterator, bool> map<Key, T>::insert(
    const Key& key, const T& obj) {
  std::pair<iterator, bool> return_value;
  bool flag = 1;
  if (!AVLTree<Key, T>::root_) {
    AVLTree<Key, T>::root_ = new typename AVLTree<Key, T>::Node(key, obj);
    return_value.first = iterator(AVLTree<Key, T>::root_);
  } else {
    flag = AVLTree<Key, T>::insert(AVLTree<Key, T>::root_, key, obj);
    return_value.first = find(key);
  }
  return_value.second = flag;
  return return_value;
}

template <typename Key, typename T>
std::pair<typename map<Key, T>::iterator, bool> map<Key, T>::insert(
    const value_type& value) {
  return insert(value.first, value.second);
}

template <typename Key, typename T>
std::pair<typename map<Key, T>::iterator, bool> map<Key, T>::insert_or_assign(
    const Key& key, const T& obj) {
  auto it = find(key);
  if (it != end()) {
    erase(it);
  }
  auto return_value = insert(key, obj);
  return_value.second = false;
  return return_value;
}

template <typename Key, typename T>
template <typename... Args>
std::vector<std::pair<typename map<Key, T>::iterator, bool>>
map<Key, T>::insert_many(Args&&... args) {
  std::vector<std::pair<iterator, bool>> return_value;
  for (const auto& arg : {args...}) {
    return_value.push_back(insert(arg));
  }
  return return_value;
}

template <typename Key, typename T>
void map<Key, T>::erase(iterator pos) {
  if (AVLTree<Key, T>::root_ && pos.node_) {
    AVLTree<Key, T>::root_ =
        AVLTree<Key, T>::deleteNode(AVLTree<Key, T>::root_, pos.node_->key_);
  }
}

template <typename Key, typename T>
void map<Key, T>::swap(map& other) {
  AVLTree<Key, T>::swap(other);
}

template <typename Key, typename T>
void map<Key, T>::merge(map& other) {
  map const_tree(other);
  iterator const_it = const_tree.begin();
  for (; const_it != const_tree.end(); ++const_it) {
    auto key = (*const_it).first;
    auto obj = (*const_it).second;
    std::pair<iterator, bool> pr = insert(key, obj);
    if (pr.second) other.erase(pr.first);
  }
}

/* MAP LOOKUP MAP LOOKUP MAP LOOKUP MAP LOOKUP MAP LOOKUP MAP LOOKUP MAP
 * LOOKUP*/

template <typename Key, typename T>
bool map<Key, T>::contains(const Key& key) {
  return AVLTree<Key, T>::contains(key);
}

template <typename Key, typename T>
typename map<Key, T>::iterator map<Key, T>::find(const Key& key) {
  typename AVLTree<Key, T>::Node* node =
      AVLTree<Key, T>::find(AVLTree<Key, T>::root_, key);
  return iterator(node);
}

}  // namespace s21