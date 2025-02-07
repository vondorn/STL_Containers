
template <typename T>
s21::vector<T>::vector() noexcept : data_(nullptr), size_(0), capacity_(0){};

template <typename T>
s21::vector<T>::vector(size_type n)
    : data_(new value_type[n]), size_(n), capacity_(n) {
  std::fill_n(data_, n, value_type());
}

template <typename T>
s21::vector<T>::vector(std::initializer_list<value_type> const &items) {
  size_ = items.size();
  capacity_ = size_;
  data_ = new value_type[size_];
  std::copy(items.begin(), items.end(), data_);
}

template <typename T>
s21::vector<T>::vector(const vector &v)
    : data_(new value_type[v.capacity_]),
      size_(v.size_),
      capacity_(v.capacity_) {
  std::copy(v.data_, v.data_ + v.size_, data_);
}

template <typename T>
s21::vector<T>::vector(vector &&v) noexcept
    : data_(v.data_), size_(v.size_), capacity_(v.capacity_) {
  v.data_ = nullptr;
  v.size_ = 0;
  v.capacity_ = 0;
}

template <typename T>
s21::vector<T>::~vector() noexcept {
  delete[] data_;
  data_ = nullptr;
  size_ = 0;
  capacity_ = 0;
}

template <typename T>
s21::vector<T> &s21::vector<T>::operator=(vector &&v) noexcept {
  if (&v != this) {
    swap(v);
    delete[] v.data_;
    v.data_ = nullptr;
    v.size_ = 0;
    v.capacity_ = 0;
  }
  return *this;
}

template <typename T>
typename s21::vector<T>::reference s21::vector<T>::at(size_type pos) {
  if (pos >= size_) {
    throw std::out_of_range("ERROR");
  }
  return data_[pos];
}

template <typename T>
typename s21::vector<T>::reference s21::vector<T>::operator[](size_type pos) {
  // if (pos >= size_) {
  //   throw std::out_of_range("ERROR");
  // }
  return data_[pos];
}

template <typename T>
typename s21::vector<T>::const_reference s21::vector<T>::front() const {
  if (!size_) {
    throw std::out_of_range("ERROR");
  }
  return data_[0];
}

template <typename T>
typename s21::vector<T>::const_reference s21::vector<T>::back() const {
  if (!size_) {
    throw std::out_of_range("ERROR");
  }
  return data_[size_ - 1];
}

template <typename T>
typename s21::vector<T>::iterator_pointer s21::vector<T>::data() noexcept {
  return data_;
}

template <typename T>
typename s21::vector<T>::size_type s21::vector<T>::size() const noexcept {
  return size_;
}

template <typename T>
typename s21::vector<T>::size_type s21::vector<T>::capacity() const noexcept {
  return capacity_;
}

template <typename value_type>
typename s21::vector<value_type>::size_type s21::vector<value_type>::max_size()
    const {
  size_type temp = 0;
  if (sizeof(value_type) == 4)
    temp = 8;
  else
    temp = sizeof(value_type);
  return std::numeric_limits<size_type>::max() / temp;
}

template <typename T>
bool s21::vector<T>::empty() const {
  return !size_;
}

template <typename T>
void s21::vector<T>::reserve(size_type size) {
  if (size > capacity_) {
    capacity_ = size;
    meme(size);
  }
}

template <typename T>
void s21::vector<T>::shrink_to_fit() {
  if (capacity_ > size_) {
    capacity_ = size_;
    meme(size_);
  }
}

template <typename T>
void s21::vector<T>::clear() noexcept {
  size_ = 0;
}

template <typename T>
void s21::vector<T>::push_back(const_reference value) {
  if (size_ == capacity_) {
    reserve(capacity_ ? capacity_ * 2 : 1);
  }
  data_[size_] = value;
  size_++;
}

template <typename T>
void s21::vector<T>::pop_back() {
  if (size_) size_--;
}

template <typename T>
void s21::vector<T>::swap(vector<T> &other) {
  std::swap(data_, other.data_);
  std::swap(size_, other.size_);
  std::swap(capacity_, other.capacity_);
}

template <typename T>
typename s21::vector<T>::iterator s21::vector<T>::begin() {
  return iterator(data_);
}

template <typename T>
typename s21::vector<T>::iterator s21::vector<T>::end() {
  return iterator(data_ + size_);
}

template <typename T>
typename s21::vector<T>::const_iterator s21::vector<T>::cbegin() const {
  return const_iterator(data_);
}

template <typename T>
typename s21::vector<T>::const_iterator s21::vector<T>::cend() const {
  return const_iterator(data_ + size_);
}

template <typename T>
typename s21::vector<T>::iterator s21::vector<T>::insert(
    iterator pos, const_reference value) {
  if ((size_type)(pos - begin()) > size_) {
    throw std::out_of_range("ERROR");
  }
  vector temp(capacity_);
  if (size_ == capacity_) {
    temp.reserve(capacity_ ? capacity_ * 2 : 1);
  }
  size_type q = 0;
  iterator i = begin(), i_temp = temp.begin();
  while (i != pos) {
    *(i_temp++) = *(i++);
  }
  q = i_temp - temp.begin();
  *(i_temp++) = value;
  while (i != end()) {
    *(i_temp++) = *(i++);
  }
  temp.size_ = size_ + 1;
  swap(temp);
  return iterator(data_ + q);
}

template <typename T>
void s21::vector<T>::erase(iterator pos) {
  if ((size_type)(pos - begin()) > size_) {
    throw std::out_of_range("ERROR");
  }
  iterator i = pos;
  while (i != end() - 1) {
    *(i++) = *(i + 1);
    if (i == pos) i++;
  }
  size_--;
}

template <typename T>
template <typename... Args>
void s21::vector<T>::insert_many_back(Args &&...args) {
  (push_back(args), ...);
}

template <typename T>
void s21::vector<T>::meme(size_type n) {
  iterator_pointer data_temp = new value_type[n];
  std::copy(data_, data_ + size_, data_temp);
  delete[] data_;
  data_ = data_temp;
}

template <typename T>
template <typename... Args>
typename s21::vector<T>::iterator s21::vector<T>::insert_many(
    const_iterator pos, Args &&...args) {
  vector<value_type> temp{args...};
  iterator cur_pos = begin() + (pos - cbegin());
  for (size_t i = 0; i < temp.size(); ++i) {
    cur_pos = insert(cur_pos, temp[i]);
    cur_pos++;
  }
  return cur_pos;
}