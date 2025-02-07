namespace s21 {
template <typename T>
list<T>::ListIterator::ListIterator() : node_(nullptr), tail_(nullptr){};

template <typename T>
list<T>::ListIterator::ListIterator(Node *node) : node_(node){};

template <typename T>
list<T>::ListIterator::ListIterator(Node *node, Node *tail)
    : node_(node), tail_(tail){};

template <typename T>
typename list<T>::reference list<T>::ListIterator::operator*() {
  return node_->value_;
}

template <typename T>
typename list<T>::iterator &list<T>::ListIterator::operator++() {
  if (node_ != nullptr) {
    node_ = node_->next_;
  }
  return *this;
}

template <typename T>
typename list<T>::iterator &list<T>::ListIterator::operator--() {
  if (node_ == nullptr && tail_ != nullptr) {
    node_ = tail_;
  } else if (node_ != nullptr) {
    node_ = node_->prev_;
  }
  return *this;
}

template <typename T>
typename list<T>::iterator list<T>::ListIterator::operator++(int) {
  iterator temp(node_);
  ++(*this);
  return temp;
}

template <typename T>
typename list<T>::iterator list<T>::ListIterator::operator--(int) {
  iterator temp(node_);
  --(*this);
  return temp;
}

template <typename T>
bool list<T>::ListIterator::operator==(const iterator &other) const {
  return node_ == other.node_;
}

template <typename T>
bool list<T>::ListIterator::operator!=(const iterator &other) const {
  return node_ != other.node_;
}

// template <typename T>
// bool list<T>::ListIterator::operator<(const iterator &other) const {
//   return node_ < other.node_;
// }

template <typename T>
list<T>::ListConstIterator::ListConstIterator() : node_(nullptr){};

template <typename T>
list<T>::ListConstIterator::ListConstIterator(const Node *node) : node_(node){};

template <typename T>
list<T>::ListConstIterator::ListConstIterator(const iterator &it)
    : node_(it.node_){};

template <typename T>
typename list<T>::const_reference list<T>::ListConstIterator::operator*() {
  return node_->value_;
}

template <typename T>
typename list<T>::const_iterator &list<T>::ListConstIterator::operator++() {
  if (node_ != nullptr) {
    node_ = node_->next_;
  }
  return *this;
}

template <typename T>
typename list<T>::const_iterator &list<T>::ListConstIterator::operator--() {
  if (node_ != nullptr) {
    node_ = node_->prev_;
  }
  return *this;
}

template <typename T>
typename list<T>::const_iterator list<T>::ListConstIterator::operator++(int) {
  iterator temp(node_);
  ++(*this);
  return temp;
}

template <typename T>
typename list<T>::const_iterator list<T>::ListConstIterator::operator--(int) {
  iterator temp(node_);
  --(*this);
  return temp;
}

template <typename T>
bool list<T>::ListConstIterator::operator==(const const_iterator &other) const {
  return node_ == other.node_;
}

template <typename T>
bool list<T>::ListConstIterator::operator!=(const const_iterator &other) const {
  return node_ != other.node_;
}

template <typename T>
typename list<T>::Node list<T>::ListIterator::get_node() const noexcept {
  return node_;
}

template <typename T>
typename list<T>::Node list<T>::ListConstIterator::get_node() const noexcept {
  return node_;
}
}  // namespace s21