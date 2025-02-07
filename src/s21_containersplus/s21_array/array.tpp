namespace s21 {
template <typename T, size_t N>
array<T, N>::array() : size_(N) {
  fill(0);
}

template <typename T, size_t N>
array<T, N>::array(std::initializer_list<value_type> const &items) : array() {
  size_type i = 0;
  for (value_type item : items) {
    arr_[i++] = item;
  }
}

template <typename T, size_t N>
array<T, N>::array(const array &a) : array() {
  for (size_type i = 0; i < size_; i++) {
    arr_[i] = a.arr_[i];
  }
}

template <typename T, size_t N>
array<T, N>::array(array &&a) noexcept : array(a) {}

template <typename T, size_t N>
array<T, N>::~array() {}

template <typename T, size_t N>
array<T, N> &array<T, N>::operator=(array &&a) {
  if (&a != this) {
    for (size_type i = 0; i < size_; i++) {
      arr_[i] = a.arr_[i];
    }
  }
  return *this;
}

template <typename T, size_t N>
array<T, N> &array<T, N>::operator=(const array &a) {
  if (&a != this) {
    size_type i = 0;
    for (value_type item : a.arr_) {
      arr_[i++] = item;
    }
  }
  return *this;
}

template <typename T, size_t N>
typename array<T, N>::reference array<T, N>::at(size_type pos) {
  if (pos >= size_) {
    throw std::out_of_range("ERROR");
  }
  return arr_[pos];
}

template <typename T, size_t N>
typename array<T, N>::reference array<T, N>::operator[](size_type pos) {
  return arr_[pos];
}

template <typename T, size_t N>
typename array<T, N>::const_reference array<T, N>::at(size_type pos) const {
  if (pos >= size_) {
    throw std::out_of_range("ERROR");
  }
  return arr_[pos];
}

template <typename T, size_t N>
typename array<T, N>::const_reference array<T, N>::operator[](
    size_type pos) const {
  return arr_[pos];
}

template <typename T, size_t N>
typename array<T, N>::const_reference array<T, N>::front() {
  return *arr_;
}

template <typename T, size_t N>
typename array<T, N>::const_reference array<T, N>::back() {
  return arr_[size_ - 1];
}

template <typename T, size_t N>
typename array<T, N>::iterator array<T, N>::data() {
  return arr_;
}

template <typename T, size_t N>
typename array<T, N>::iterator array<T, N>::begin() {
  return arr_;
}

template <typename T, size_t N>
typename array<T, N>::iterator array<T, N>::end() {
  return arr_ + size_;
}

template <typename T, size_t N>
bool array<T, N>::empty() {
  return size_ == 0;
}

template <typename T, size_t N>
typename array<T, N>::size_type array<T, N>::size() {
  return size_;
}

template <typename T, size_t N>
typename array<T, N>::size_type array<T, N>::max_size() {
  return size();
}

template <typename T, size_t N>
void array<T, N>::swap(array &other) {
  value_type temp;
  for (size_type i = 0; i < size_; i++) {
    temp = other.arr_[i];
    other.arr_[i] = arr_[i];
    arr_[i] = temp;
  }
}

template <typename T, size_t N>
void array<T, N>::fill(const_reference value) {
  for (size_type i = 0; i < size_; i++) {
    arr_[i] = value;
  }
}

}  // namespace s21