namespace s21 {
template <typename T>
list<T>::list() : head_(nullptr), tail_(nullptr), size_(0U){};

template <typename T>
list<T>::list(size_type n) : list() {
  if (n > 0) {
    for (size_type i = 0; i < n; i++) {
      push_back(value_type());
    }
  }
};

template <typename T>
list<T>::list(std::initializer_list<value_type> const &items) : list() {
  for (value_type i : items) {
    push_back(i);
  }
};

template <typename T>
list<T>::list(const list &l) : list() {
  Node *cur = l.head_;
  while (cur != nullptr) {
    push_back(cur->value_);
    cur = cur->next_;
  }
};

template <typename T>
list<T>::list(list &&l) {
  size_ = l.size_;
  head_ = l.head_;
  tail_ = l.tail_;
  l.size_ = 0;
  l.head_ = nullptr;
  l.tail_ = nullptr;
};

template <typename T>
list<T>::~list() noexcept {
  clear();
  // size_ = 0;
  // head_ = nullptr;
  // tail_ = nullptr;
};

template <typename T>
list<T> &list<T>::operator=(list &&l) {
  if (&l != this) {
    swap(l);
  }
  return *this;
};

template <typename T>
list<T> &list<T>::operator=(const list &l) {
  if (&l != this) {
    clear();
    for (Node *temp = l.head_; temp != nullptr; temp = temp->next_) {
      push_back(temp->value_);
    }
  }
  return *this;
};

template <typename T>
typename list<T>::const_reference list<T>::front() const {
  return head_->value_;
};

template <typename T>
typename list<T>::const_reference list<T>::back() const {
  return tail_->value_;
};

template <typename T>
typename list<T>::iterator list<T>::begin() noexcept {
  return iterator(head_, tail_);
};

// template <typename T>
// typename list<T>::const_iterator list<T>::begin() const noexcept {
//   return const_iterator(head_);
// };

// template <typename T>
// typename list<T>::const_iterator list<T>::cbegin() const noexcept {
//   return const_iterator(head_);
// };

template <typename T>
typename list<T>::iterator list<T>::end() noexcept {
  return iterator(nullptr, tail_);
};

// template <typename T>
// typename list<T>::const_iterator list<T>::end() const noexcept {
//   return const_iterator(nullptr);
// };

// template <typename T>
// typename list<T>::const_iterator list<T>::cend() const noexcept {
//   return const_iterator(nullptr);
// };

template <typename T>
bool list<T>::empty() const noexcept {
  return size_ == 0;
};

template <typename T>
typename list<T>::size_type list<T>::size() const noexcept {
  return size_;
};

template <typename T>
typename list<T>::size_type list<T>::max_size() const noexcept {
  return std::numeric_limits<size_type>::max() / sizeof(Node) / 2;
};

template <typename T>
typename list<T>::iterator list<T>::insert(iterator pos,
                                           const_reference value) {
  if (pos == begin()) {
    push_front(value);
    return iterator(head_);
  } else if (pos == end()) {
    push_back(value);
    return iterator(tail_);
  } else {
    Node *cur = pos.node_;
    Node *blank = new Node(value);
    blank->next_ = cur;
    blank->prev_ = cur->prev_;
    if (cur->prev_) {
      cur->prev_->next_ = blank;
    }
    cur->prev_ = blank;
    size_++;
    return iterator(blank);
  }
};

template <typename T>
void list<T>::push_back(const_reference value) {
  Node *cur = new Node(value);
  cur->next_ = nullptr;

  if (tail_ == nullptr) {
    head_ = cur;
    tail_ = cur;
    cur->prev_ = nullptr;
  } else {
    cur->prev_ = tail_;
    tail_->next_ = cur;
    tail_ = cur;
  }

  size_++;
};

template <typename T>
void list<T>::push_front(const_reference value) {
  Node *cur = new Node(value);
  cur->prev_ = nullptr;
  cur->next_ = head_;
  if (head_ != nullptr) {
    head_->prev_ = nullptr;
  }
  head_ = cur;
  if (tail_ == nullptr) {
    tail_ = cur;
  }
  size_++;
};

template <typename T>
void list<T>::pop_back() {
  if (tail_ != nullptr) {
    Node *temp = tail_;
    tail_ = tail_->prev_;
    if (tail_ != nullptr) {
      tail_->next_ = nullptr;
    } else {
      head_ = nullptr;
    }
    delete temp;
    size_--;
  }
};

template <typename T>
void list<T>::pop_front() {
  if (head_ != nullptr) {
    Node *temp = head_;
    head_ = head_->next_;
    if (head_ != nullptr) {
      head_->prev_ = nullptr;
    } else {
      tail_ = nullptr;
    }
    delete temp;
    size_--;
  }
};

template <typename T>
void list<T>::clear() noexcept {
  while (!empty()) {
    pop_front();
  }
};

template <typename T>
void list<T>::erase(iterator pos) {
  if (pos == end()) {
    throw std::out_of_range("Cannot erase");
  }
  Node *temp = pos.node_;
  if (temp == head_) {
    pop_front();
  } else if (temp == tail_) {
    pop_back();
  } else {
    temp->prev_->next_ = temp->next_;
    temp->next_->prev_ = temp->prev_;
    delete temp;
    size_--;
  }
};

template <typename T>
void list<T>::swap(list &other) {
  std::swap(size_, other.size_);
  std::swap(head_, other.head_);
  std::swap(tail_, other.tail_);
};

template <typename T>
void list<T>::merge(list &other) {
  if (this != &other) {
    iterator iter_this = begin();
    iterator iter_other = other.begin();
    while (iter_other != other.end()) {
      if (iter_this == end() || *iter_other < *iter_this) {
        insert(iter_this, *iter_other);
        other.erase(iter_other++);
      } else {
        ++iter_this;
      }
    }
  }
};

template <typename T>
void list<T>::reverse() {
  if (head_ != nullptr) {
    Node *cur = head_;
    Node *temp = nullptr;
    while (cur != nullptr) {
      temp = cur->prev_;
      cur->prev_ = cur->next_;
      cur->next_ = temp;
      cur = cur->prev_;
    }
    std::swap(head_, tail_);
  }
};

template <typename T>
void list<T>::unique() {
  if (!empty()) {
    Node *cur = head_;

    while (cur != nullptr && cur->next_ != nullptr) {
      if (cur->value_ == cur->next_->value_) {
        Node *temp = cur->next_;
        cur->next_ = temp->next_;

        if (temp->next_ != nullptr) {
          temp->next_->prev_ = cur;
        } else {
          tail_ = cur;
        }

        delete temp;
        size_--;
      } else {
        cur = cur->next_;
      }
    }
  }
};

// template <typename T>
// void list<T>::resize(size_type count) {
//   if (max_size() >= count) {
//     size_ = count;
//   } else {
//     throw std::out_of_range("ERROR");
//   }
// };

template <typename T>
void list<T>::splice(const_iterator pos, list &other) {
  if (this != &other && !other.empty()) {
    Node *first_other_node = other.head_;
    Node *last_other_node = other.tail_;

    // Подключаем диапазон элементов из other в список this
    if (pos.node_ == head_) {  // Вставляем в начало списка
      other.tail_->next_ = head_;
      head_->prev_ = other.tail_;
      head_ = first_other_node;
    } else if (pos.node_ == nullptr) {  // Вставляем в конец списка
      tail_->next_ = first_other_node;
      first_other_node->prev_ = tail_;
      tail_ = last_other_node;
    } else {  // Вставляем в середину списка
      Node *cur = pos.node_;
      first_other_node->prev_ = cur->prev_;
      last_other_node->next_ = cur;
      cur->prev_->next_ = first_other_node;
      cur->prev_ = last_other_node;
    }

    size_ += other.size_;

    other.head_ = nullptr;
    other.tail_ = nullptr;
    other.size_ = 0;
  }
}

template <typename T>
void list<T>::sort() {
  if (size_ > 1) {
    head_ = mergeSort(head_);

    Node *cur = head_;
    while (cur->next_ != nullptr) {
      cur = cur->next_;
    }
    tail_ = cur;
  }
};

template <typename T>
typename list<T>::Node *list<T>::mergeNode(Node *left, Node *right) {
  if (!left) return right;
  if (!right) return left;

  if (left->value_ <= right->value_) {
    left->next_ = mergeNode(left->next_, right);
    if (left->next_) {
      left->next_->prev_ = left;
    }
    return left;
  } else {
    right->next_ = mergeNode(left, right->next_);
    if (right->next_) {
      right->next_->prev_ = right;
    }
    return right;
  }
}

template <typename T>
typename list<T>::Node *list<T>::mergeSort(Node *head) {
  if (!head || !head->next_) {
    return head;
  }

  Node *slow = head;
  Node *fast = head->next_;

  while (fast && fast->next_) {
    slow = slow->next_;
    fast = fast->next_->next_;
  }

  Node *middle = slow->next_;
  slow->next_ = nullptr;

  if (middle) {
    middle->prev_ = nullptr;
  }
  Node *left = mergeSort(head);
  Node *right = mergeSort(middle);
  return mergeNode(left, right);
};

template <typename T>
template <typename... Args>
typename list<T>::iterator list<T>::insert_many(const_iterator pos,
                                                Args &&...args) {
  iterator iter_last = pos;
  if (pos == begin()) {
    (push_front(args), ...);
  } else if (pos == end()) {
    (push_back(args), ...);
  } else {
    ((iter_last = insert(pos, args)), ...);
  }
  return iter_last;
}

template <typename T>
template <typename... Args>
void list<T>::insert_many_back(Args &&...args) {
  (push_back(args), ...);
}

template <typename T>
template <typename... Args>
void list<T>::insert_many_front(Args &&...args) {
  (push_front(args), ...);
}
}  // namespace s21