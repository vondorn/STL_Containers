// Copyright 2024 granceti aka vsem privet and fredgran
#include <vector>

#include "./s21_main_test.h"

void vectorCompare(s21::vector<int> test, std::vector<int> origin) {
  EXPECT_EQ(test.size(), origin.size());
  auto i1 = test.begin();
  auto i2 = origin.begin();
  while (i1 != test.end() || i2 != origin.end()) {
    EXPECT_EQ(*(i1++), *(i2++));
  }
}

TEST(Constructors, Default) {
  s21::vector<int> test;
  std::vector<int> origin;
  EXPECT_EQ(test.size(), origin.size());
  EXPECT_EQ(test.capacity(), origin.capacity());
  EXPECT_EQ(test.empty(), origin.empty());
}

TEST(Constructors, Size) {
  s21::vector<int> test(12);
  std::vector<int> origin(12);
  EXPECT_EQ(test.capacity(), origin.capacity());
  vectorCompare(test, origin);
}

TEST(Constructors, List) {
  s21::vector<int> test = {1, 2, 3, 4, 5};
  std::vector<int> origin = {1, 2, 3, 4, 5};
  EXPECT_EQ(test.capacity(), origin.capacity());
  vectorCompare(test, origin);
}

TEST(Constructors, Copy) {
  s21::vector<int> t = {1, 2, 3, 4, 5};
  std::vector<int> o = {1, 2, 3, 4, 5};
  s21::vector<int> test(t);
  std::vector<int> origin(o);
  EXPECT_EQ(test.capacity(), origin.capacity());
  vectorCompare(test, origin);
}

TEST(Constructors, Eq) {
  s21::vector<int> t = {1, 2, 3, 4, 5};
  std::vector<int> o = {1, 2, 3, 4, 5};
  s21::vector<int> test = t;
  std::vector<int> origin = o;
  EXPECT_EQ(test.capacity(), origin.capacity());
  vectorCompare(test, origin);
}

TEST(Constructors, Move) {
  s21::vector<int> t = {1, 2, 3, 4, 5};
  std::vector<int> o = {1, 2, 3, 4, 5};
  s21::vector<int> test;
  test = std::move(t);
  std::vector<int> origin;
  origin = std::move(o);
  EXPECT_EQ(test.capacity(), origin.capacity());
  vectorCompare(test, origin);
}

TEST(Operators, Eq) {
  s21::vector<int> t = {1, 2, 3, 4, 5};
  std::vector<int> o = {1, 2, 3, 4, 5};
  s21::vector<int> test(std::move(t));
  std::vector<int> origin(std::move(o));
  EXPECT_EQ(test.capacity(), origin.capacity());
  vectorCompare(test, origin);
}

TEST(ElementAccess, At) {
  s21::vector<int> test = {1, 2, 3, 4, 5};
  std::vector<int> origin = {1, 2, 3, 4, 5};
  for (int i = 0; i < 5; i++) {
    EXPECT_EQ(test.at(i)++, origin.at(i)++);
    EXPECT_EQ(test.at(i), origin.at(i));
  }
}

TEST(ElementAccess, AtThrow) {
  s21::vector<int> test = {1, 2, 3, 4, 5};
  std::vector<int> origin = {1, 2, 3, 4, 5};
  EXPECT_THROW(test.at(test.size() + 1), std::out_of_range);
}

TEST(ElementAccess, SquareBrack) {
  s21::vector<int> test = {1, 2, 3, 4, 5};
  std::vector<int> origin = {1, 2, 3, 4, 5};
  for (int i = 0; i < 5; i++) {
    EXPECT_EQ(test[i]++, origin[i]++);
    EXPECT_EQ(test[i], origin[i]);
  }
}

TEST(ElementAccess, Front) {
  s21::vector<int> test = {1, 2, 3, 4, 5};
  std::vector<int> origin = {1, 2, 3, 4, 5};
  EXPECT_EQ(test.front(), origin.front());
}

TEST(ElementAccess, FrontThrow) {
  s21::vector<int> test;
  EXPECT_THROW(test.front(), std::out_of_range);
}

TEST(ElementAccess, Back) {
  s21::vector<int> test = {1, 2, 3, 4, 5};
  std::vector<int> origin = {1, 2, 3, 4, 5};
  EXPECT_EQ(test.back(), origin.back());
}

TEST(ElementAccess, BackThrow) {
  s21::vector<int> test;
  EXPECT_THROW(test.back(), std::out_of_range);
}

TEST(ElementAccess, Data) {
  s21::vector<int> test = {1, 2, 3, 4, 5};
  std::vector<int> origin = {1, 2, 3, 4, 5};
  EXPECT_EQ(*test.data(), *origin.data());
}

TEST(Capacity, MaxSize) {
  s21::vector<int> test = {1, 2, 3, 4, 5};
  std::vector<int> origin = {1, 2, 3, 4, 5};
  EXPECT_EQ(test.max_size(), origin.max_size());
}

TEST(Capacity, Reserve) {
  s21::vector<int> test(12);
  std::vector<int> origin(12);
  test.reserve(50);
  origin.reserve(50);
  EXPECT_EQ(test.capacity(), origin.capacity());
  test.shrink_to_fit();
  origin.shrink_to_fit();
  EXPECT_EQ(test.capacity(), origin.capacity());
}

TEST(Iterators, Begin) {
  s21::vector<int> test = {1, 2, 3, 4, 5};
  std::vector<int> origin = {1, 2, 3, 4, 5};
  auto i1 = test.begin();
  auto i2 = origin.begin();
  EXPECT_EQ(*i1, *i2);
}

TEST(Iterators, CBegin) {
  s21::vector<int> test = {1, 2, 3, 4, 5};
  std::vector<int> origin = {1, 2, 3, 4, 5};
  auto i1 = test.cbegin();
  auto i2 = origin.cbegin();
  EXPECT_EQ(*i1, *i2);
}

TEST(Iterators, End) {
  s21::vector<int> test = {1, 2, 3, 4, 5};
  std::vector<int> origin = {1, 2, 3, 4, 5};
  auto i1 = test.end();
  auto i2 = origin.end();
  EXPECT_EQ(*(--i1), *(--i2));
}

TEST(Iterators, CEnd) {
  s21::vector<int> test = {1, 2, 3, 4, 5};
  std::vector<int> origin = {1, 2, 3, 4, 5};
  auto i1 = test.cend();
  auto i2 = origin.cend();
  EXPECT_EQ(*(--i1), *(--i2));
}

TEST(Modifiers, Clear) {
  s21::vector<int> test = {1, 2, 3, 4, 5};
  std::vector<int> origin = {1, 2, 3, 4, 5};
  test.clear();
  origin.clear();
  EXPECT_EQ(test.size(), origin.size());
  EXPECT_EQ(test.capacity(), origin.capacity());
  EXPECT_EQ(test.empty(), origin.empty());
}

TEST(Modifiers, PushBack) {
  s21::vector<int> test = {1, 2, 3, 4, 5};
  std::vector<int> origin = {1, 2, 3, 4, 5};
  test.push_back(6);
  origin.push_back(6);
  EXPECT_EQ(test.back(), origin.back());
  test.pop_back();
  origin.pop_back();
  EXPECT_EQ(test.back(), origin.back());
}

TEST(Modifiers, Swap) {
  s21::vector<int> test = {1, 2, 3, 4, 5};
  std::vector<int> origin = {1, 2, 3, 4, 5};
  s21::vector<int> test2 = {101, 102, 103, 104, 105};
  std::vector<int> origin2 = {101, 102, 103, 104, 105};
  test.swap(test2);
  origin.swap(origin2);
  EXPECT_EQ(test.capacity(), origin.capacity());
  vectorCompare(test, origin);
}

TEST(Modifiers, Insert) {
  s21::vector<int> test = {1, 2, 3, 4, 5};
  std::vector<int> origin = {1, 2, 3, 4, 5};
  test.insert(test.begin() + 4, 88);
  origin.insert(origin.begin() + 4, 88);
  EXPECT_EQ(test.capacity(), origin.capacity());
  vectorCompare(test, origin);
  test.insert(test.begin(), 0);
  origin.insert(origin.begin(), 0);
  EXPECT_EQ(test.capacity(), origin.capacity());
  vectorCompare(test, origin);
}

TEST(Modifiers, InsertThrow) {
  s21::vector<int> test = {1, 2, 3, 4, 5};
  EXPECT_THROW(test.insert(test.begin() + 10, 88), std::out_of_range);
}

TEST(Modifiers, Erase) {
  s21::vector<int> test = {1, 2, 3, 4, 5};
  std::vector<int> origin = {1, 2, 3, 4, 5};
  test.erase(test.begin() + 1);
  origin.erase(origin.begin() + 1);
  EXPECT_EQ(test.capacity(), origin.capacity());
  vectorCompare(test, origin);
}

TEST(Modifiers, EraseThrow) {
  s21::vector<int> test = {1, 2, 3, 4, 5};
  EXPECT_THROW(test.erase(test.begin() + 10), std::out_of_range);
}

TEST(Iterators, EverythingEverywhereAllAtOnce) {
  s21::vector<int> test = {1, 2, 3, 4, 5};
  std::vector<int> origin = {1, 2, 3, 4, 5};
  s21::vector<int>::iterator i1;
  std::vector<int>::iterator i2;
  i1 = test.begin();
  i2 = origin.begin();
  EXPECT_EQ(*(i1++), *(i2++));
  EXPECT_EQ(*(++i1), *(++i2));
  EXPECT_EQ(*(i1--), *(i2--));
  EXPECT_EQ(*(--i1), *(--i2));
  EXPECT_EQ(*(i1 + 2), *(i2 + 2));
}

TEST(Vector, Insert_Many_Back) {
  s21::vector<int> test = {1, 2, 3, 4, 5};
  std::vector<int> origin = {1, 2, 3, 4, 5};
  test.insert_many_back(6, 7, 8);
  origin.push_back(6);
  origin.push_back(7);
  origin.push_back(8);
  EXPECT_EQ(test.capacity(), origin.capacity());
  vectorCompare(test, origin);
}

TEST(Vector, Insert_Many) {
  s21::vector<int> test = {1, 5};
  std::vector<int> origin = {1, 5};
  origin.insert(origin.begin() + 1, 2);
  origin.insert(origin.begin() + 2, 3);
  origin.insert(origin.begin() + 3, 4);
  test.insert_many(test.cbegin() + 1, 2, 3, 4);
  EXPECT_EQ(test.capacity(), origin.capacity());
  vectorCompare(test, origin);
}
