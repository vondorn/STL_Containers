namespace s21 {
template <typename T>
stack<T>::stack() : top_(nullptr), size_(0U){};

template <typename T>
stack<T>::stack(std::initializer_list<value_type> const &items) : stack() {
  for (value_type i : items) {
    push(i);
  }
};

template <typename T>
stack<T>::stack(const stack &s) : stack() {
  Node *cur = s.top_;
  stack<T> temp;
  while (cur != nullptr) {
    temp.push(cur->value_);
    cur = cur->next_;
  }

  while (!temp.empty()) {
    push(temp.top_->value_);
    temp.pop();
  }
};

template <typename T>
stack<T>::stack(stack &&s) {
  size_ = s.size_;
  top_ = s.top_;
  s.size_ = 0;
  s.top_ = nullptr;
};

template <typename T>
stack<T>::~stack() noexcept {
  while (!empty()) {
    pop();
  }
  // size_ = 0;
};

template <typename T>
stack<T> &stack<T>::operator=(stack &&s) {
  if (&s != this) {
    swap(s);
  }
  return *this;
};

template <typename T>
stack<T> &stack<T>::operator=(const stack &s) {
  if (&s != this) {
    while (!empty()) {
      pop();
    }
    Node *cur = s.top_;
    stack<T> temp;
    while (cur != nullptr) {
      temp.push(cur->value_);
      cur = cur->next_;
    }
    while (!temp.empty()) {
      push(temp.top_->value_);
      temp.pop();
    }
  }
  return *this;
};

template <typename T>
typename stack<T>::const_reference stack<T>::top() const {
  return top_->value_;
};

template <typename T>
bool stack<T>::empty() {
  return size_ == 0;
};

template <typename T>
typename stack<T>::size_type stack<T>::size() {
  return size_;
};

template <typename T>
void stack<T>::push(const_reference value) {
  Node *temp = new Node(value);
  temp->next_ = top_;
  top_ = temp;
  size_++;
};

template <typename T>
void stack<T>::pop() {
  if (top_ != nullptr) {
    Node *temp = top_;
    top_ = top_->next_;
    delete temp;
    size_--;
  }
}

template <typename T>
void stack<T>::swap(stack &other) {
  std::swap(size_, other.size_);
  std::swap(top_, other.top_);
};

template <typename T>
template <typename... Args>
void stack<T>::insert_many_back(Args &&...args) {
  (push(args), ...);
}

}  // namespace s21