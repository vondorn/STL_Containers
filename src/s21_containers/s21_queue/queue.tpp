namespace s21 {
template <typename T>
queue<T>::queue() : head_(nullptr), tail_(nullptr), size_(0U){};

template <typename T>
queue<T>::queue(std::initializer_list<value_type> const &items) : queue() {
  for (value_type i : items) {
    push(i);
  }
};

template <typename T>
queue<T>::queue(const queue &q) : queue() {
  Node *cur = q.head_;
  while (cur != nullptr) {
    push(cur->value_);
    cur = cur->next_;
  }
};

template <typename T>
queue<T>::queue(queue &&q) {
  size_ = q.size_;
  head_ = q.head_;
  tail_ = q.tail_;
  q.size_ = 0;
  q.head_ = nullptr;
  q.tail_ = nullptr;
};

template <typename T>
queue<T>::~queue() noexcept {
  while (!empty()) {
    pop();
  }
  // size_ = 0;
  // head_ = nullptr;
  // tail_ = nullptr;
};

template <typename T>
queue<T> &queue<T>::operator=(queue &&q) {
  if (&q != this) {
    swap(q);
  }
  return *this;
};

template <typename T>
queue<T> &queue<T>::operator=(const queue &q) {
  if (&q != this) {
    while (!empty()) {
      pop();
    }
    for (Node *temp = q.head_; temp != nullptr; temp = temp->next_) {
      push(temp->value_);
    }
  }
  return *this;
};

template <typename T>
typename queue<T>::const_reference queue<T>::front() const {
  return head_->value_;
};

template <typename T>
typename queue<T>::const_reference queue<T>::back() const {
  return tail_->value_;
};

template <typename T>
bool queue<T>::empty() const noexcept {
  return size_ == 0;
};

template <typename T>
typename queue<T>::size_type queue<T>::size() const noexcept {
  return size_;
};

template <typename T>
void queue<T>::push(const_reference value) {
  Node *cur = new Node(value);
  cur->next_ = nullptr;
  if (tail_ == nullptr) {
    head_ = cur;
    tail_ = cur;
  } else {
    tail_->next_ = cur;
    tail_ = cur;
  }
  size_++;
};

template <typename T>
void queue<T>::pop() {
  if (head_ != nullptr) {
    Node *temp = head_;
    head_ = head_->next_;
    if (head_ == nullptr) {
      tail_ = nullptr;
    }
    delete temp;
    size_--;
  }
};

template <typename T>
void queue<T>::swap(queue &other) {
  std::swap(size_, other.size_);
  std::swap(head_, other.head_);
  std::swap(tail_, other.tail_);
}

template <typename T>
template <typename... Args>
void queue<T>::insert_many_back(Args &&...args) {
  (push(args), ...);
}

}  // namespace s21
