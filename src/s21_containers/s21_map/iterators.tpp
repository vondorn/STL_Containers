
namespace s21 {

template <typename Key, typename T>
typename map<Key, T>::value_type map<Key, T>::MapIterator::operator*() {
  if (!AVLTree<Key, T>::Iterator::node_) {
    static value_type fake_value{};
    return fake_value;
  }
  const key_type first = AVLTree<Key, T>::Iterator::node_->key_;
  mapped_type second = AVLTree<Key, T>::Iterator::node_->value_;
  std::pair<const key_type, mapped_type> pr = std::make_pair(first, second);
  return pr;
}

template <typename Key, typename T>
T& map<Key, T>::MapIterator::return_value() {
  if (!AVLTree<Key, T>::Iterator::node_) {
    static T fake_value{};
    return fake_value;
  }
  return AVLTree<Key, T>::Iterator::node_->value_;
}

}  // namespace s21