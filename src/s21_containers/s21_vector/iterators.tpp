/*  ITERATORS  ITERATORS  ITERATORS  ITERATORS  ITERATORS  ITERATORS  */

template <typename T>
s21::vector<T>::VectorIterator::VectorIterator() : ptr_(nullptr){};

template <typename T>
s21::vector<T>::VectorIterator::VectorIterator(iterator_pointer ptr)
    : ptr_(ptr){};

template <typename T>
typename s21::vector<T>::reference s21::vector<T>::VectorIterator::operator*() {
  return *ptr_;
}

template <typename T>
typename s21::vector<T>::iterator s21::vector<T>::VectorIterator::operator++(
    int) {
  iterator res(*this);
  ptr_++;
  return res;
}

template <typename T>
typename s21::vector<T>::iterator s21::vector<T>::VectorIterator::operator--(
    int) {
  iterator res(*this);
  ptr_--;
  return res;
}

template <typename T>
typename s21::vector<T>::iterator s21::vector<T>::VectorIterator::operator++() {
  ptr_++;
  return *this;
}

template <typename T>
typename s21::vector<T>::iterator s21::vector<T>::VectorIterator::operator--() {
  ptr_--;
  return *this;
}

template <typename T>
typename s21::vector<T>::iterator s21::vector<T>::VectorIterator::operator+(
    int n) const {
  iterator res(*this);
  res.ptr_ += n;
  return res;
}

template <typename T>
typename s21::vector<T>::iterator s21::vector<T>::VectorIterator::operator-(
    int n) const {
  iterator res(*this);
  res.ptr_ -= n;
  return res;
}

template <typename T>
bool s21::vector<T>::VectorIterator::operator==(const iterator& other) const {
  return ptr_ == other.ptr_;
}

template <typename T>
bool s21::vector<T>::VectorIterator::operator!=(const iterator& other) const {
  return ptr_ != other.ptr_;
}

template <typename T>
ptrdiff_t s21::vector<T>::VectorIterator::operator-(
    const iterator& other) const {
  return ptr_ - other.ptr_;
}

template <typename T>
s21::vector<T>::VectorConstIterator::VectorConstIterator() : ptr_(nullptr){};

template <typename T>
s21::vector<T>::VectorConstIterator::VectorConstIterator(iterator_pointer ptr)
    : ptr_(ptr){};

template <typename T>
typename s21::vector<T>::const_reference
s21::vector<T>::VectorConstIterator::operator*() {
  return *ptr_;
}

template <typename T>
typename s21::vector<T>::const_iterator
s21::vector<T>::VectorConstIterator::operator++(int) {
  const_iterator res(*this);
  ptr_++;
  return res;
}

template <typename T>
typename s21::vector<T>::const_iterator
s21::vector<T>::VectorConstIterator::operator--(int) {
  const_iterator res(*this);
  ptr_--;
  return res;
}

template <typename T>
typename s21::vector<T>::const_iterator
s21::vector<T>::VectorConstIterator::operator++() {
  ptr_++;
  return *this;
}

template <typename T>
typename s21::vector<T>::const_iterator
s21::vector<T>::VectorConstIterator::operator--() {
  ptr_--;
  return *this;
}

template <typename T>
typename s21::vector<T>::const_iterator
s21::vector<T>::VectorConstIterator::operator+(int n) const {
  const_iterator res(*this);
  res.ptr_ += n;
  return res;
}

template <typename T>
typename s21::vector<T>::const_iterator
s21::vector<T>::VectorConstIterator::operator-(int n) const {
  const_iterator res(*this);
  res.ptr_ -= n;
  return res;
}

template <typename T>
bool s21::vector<T>::VectorConstIterator::operator==(
    const const_iterator& other) const {
  return ptr_ == other.ptr_;
}

template <typename T>
bool s21::vector<T>::VectorConstIterator::operator!=(
    const const_iterator& other) const {
  return ptr_ != other.ptr_;
}

template <typename T>
ptrdiff_t s21::vector<T>::VectorConstIterator::operator-(
    const const_iterator& other) const {
  return ptr_ - other.ptr_;
}