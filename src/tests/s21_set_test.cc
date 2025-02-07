// Copyright 2024 granceti aka vsem privet and fredgran
#include <set>

#include "./s21_main_test.h"

void abc(s21::set<int> s21, std::set<int> std) {
  EXPECT_EQ(s21.size(), std.size());
  EXPECT_EQ(s21.empty(), std.empty());
  auto it = s21.begin();
  auto wo = std.begin();
  for (; it != s21.end() && wo != std.end(); it++, wo++) {
    EXPECT_EQ(*it, *wo);
  }
}

TEST(Set, Constructors_1) {
  s21::set<int> s21_set;
  std::set<int> std_set;
  EXPECT_EQ(s21_set.empty(), std_set.empty());
}

TEST(Set, Constructors_2) {
  s21::set<int> s21_set_1 = {1, 2, 3};
  std::set<int> std_set_1 = {1, 2, 3};
  abc(s21_set_1, std_set_1);
}

TEST(Set, Constructors_3) {
  s21::set<int> s21_set_1 = {1, 2, 3};
  std::set<int> std_set_1 = {1, 2, 3};
  s21::set<int> s21_set_2(s21_set_1);
  std::set<int> std_set_2(std_set_1);
  abc(s21_set_2, std_set_2);
}

TEST(Set, Constructors_4) {
  s21::set<int> s21_set_1 = {1, 2, 3};
  std::set<int> std_set_1 = {1, 2, 3};
  s21::set<int> s21_set_3(std::move(s21_set_1));
  std::set<int> std_set_3(std::move(std_set_1));
  abc(s21_set_3, std_set_3);
  abc(s21_set_1, std_set_1);
}

TEST(Set, Operators_1) {
  s21::set<int> s21_set_1 = {1, 2, 3};
  std::set<int> std_set_1 = {1, 2, 3};
  s21::set<int> s21_set_2;
  s21_set_2 = s21_set_1;
  std::set<int> std_set_2;
  std_set_2 = std_set_1;
  abc(s21_set_2, std_set_2);
}

TEST(Set, Operators_2) {
  s21::set<int> s21_set_1 = {1, 2, 3};
  std::set<int> std_set_1 = {1, 2, 3};
  s21::set<int> s21_set_2;
  s21_set_2 = std::move(s21_set_1);
  std::set<int> std_set_2;
  std_set_2 = std::move(std_set_1);
  abc(s21_set_2, std_set_2);
}

TEST(Set, Iterators) {
  s21::set<int> s21_set_1 = {1, 2, 3};
  std::set<int> std_set_1 = {1, 2, 3};
  auto s21_it = s21_set_1.begin();
  auto std_it = std_set_1.begin();
  EXPECT_EQ(*s21_it, *std_it);
  s21_it = s21_set_1.end();
  std_it = std_set_1.end();
  EXPECT_EQ(*(--s21_it), *(--std_it));
}

TEST(Set, Empty) {
  s21::set<int> s21_set_1;
  std::set<int> std_set_1;
  EXPECT_EQ(s21_set_1.empty(), s21_set_1.empty());
  s21::set<int> s21_set_2 = {1, 2, 3};
  std::set<int> std_set_2 = {1, 2, 3};
  EXPECT_EQ(s21_set_2.empty(), s21_set_2.empty());
}

TEST(Set, Size) {
  s21::set<int> s21_set_1;
  std::set<int> std_set_1;
  EXPECT_EQ(s21_set_1.size(), s21_set_1.size());
  s21::set<int> s21_set_2 = {1, 2, 3};
  std::set<int> std_set_2 = {1, 2, 3};
  EXPECT_EQ(s21_set_2.size(), s21_set_2.size());
}

TEST(Set, MaxSize) {
  s21::set<int> s21_set_1;
  std::set<int> std_set_1;
  EXPECT_EQ(s21_set_1.max_size(), s21_set_1.max_size());
  s21::set<int> s21_set_2 = {1, 2, 3};
  std::set<int> std_set_2 = {1, 2, 3};
  EXPECT_EQ(s21_set_2.max_size(), s21_set_2.max_size());
}

TEST(Set, Clear) {
  s21::set<int> s21_set_1 = {1, 2, 3};
  std::set<int> std_set_1 = {1, 2, 3};
  s21_set_1.clear();
  std_set_1.clear();
  abc(s21_set_1, std_set_1);
}

TEST(Set, Insert) {
  s21::set<int> s21_set_1;
  std::set<int> std_set_1;
  s21_set_1.insert(1);
  std_set_1.insert(1);
  abc(s21_set_1, std_set_1);
  s21::set<int> s21_set_2 = {1, 2, 3};
  std::set<int> std_set_2 = {1, 2, 3};
  s21_set_2.insert(4);
  std_set_2.insert(4);
  abc(s21_set_2, std_set_2);
  s21_set_2.insert(1);
  std_set_2.insert(1);
  abc(s21_set_2, std_set_2);
}

TEST(Set, Contains) {
  s21::set<int> s21_set_1;
  std::set<int> std_set_1;
  EXPECT_EQ(s21_set_1.contains(3), s21_set_1.contains(3));
  s21::set<int> s21_set_2 = {1, 2, 3};
  std::set<int> std_set_2 = {1, 2, 3};
  EXPECT_EQ(s21_set_2.contains(3), s21_set_2.contains(3));
}

TEST(Set, Erase) {
  s21::set<int> s21_set_1 = {1, 2, 3};
  std::set<int> std_set_1 = {1, 2, 3};
  auto it = s21_set_1.find(3);
  auto wo = std_set_1.find(3);
  s21_set_1.erase(it);
  std_set_1.erase(wo);
  abc(s21_set_1, std_set_1);
}

TEST(Set, Swap) {
  s21::set<int> s21_set_1 = {1, 2, 3};
  std::set<int> std_set_1 = {1, 2, 3};
  s21::set<int> s21_set_2 = {4, 5, 6};
  std::set<int> std_set_2 = {4, 5, 6};
  s21_set_1.swap(s21_set_2);
  std_set_1.swap(std_set_2);
  abc(s21_set_1, std_set_1);
  abc(s21_set_2, std_set_2);
}

TEST(Set, Merge) {
  s21::set<int> s21_set_1 = {1, 2, 3};
  std::set<int> std_set_1 = {1, 2, 3};
  s21::set<int> s21_set_2 = {4, 5, 6};
  std::set<int> std_set_2 = {4, 5, 6};
  s21_set_1.merge(s21_set_2);
  std_set_1.merge(std_set_2);
  abc(s21_set_1, std_set_1);
  abc(s21_set_2, std_set_2);
  s21::set<int> s21_set_3 = {1, 2, 3};
  std::set<int> std_set_3 = {1, 2, 3};
  s21::set<int> s21_set_4 = {3, 4};
  std::set<int> std_set_4 = {3, 4};
  s21_set_3.merge(s21_set_4);
  std_set_3.merge(std_set_4);
  abc(s21_set_3, std_set_3);
  abc(s21_set_4, std_set_4);
}

TEST(Set, Find) {
  s21::set<int> s21_set_1 = {1, 2, 6, 7, 8};
  std::set<int> std_set_1 = {1, 2, 6, 7, 8};
  EXPECT_EQ(*s21_set_1.find(1), *std_set_1.find(1));
  EXPECT_EQ(*s21_set_1.find(3), *std_set_1.find(3));
  EXPECT_EQ(*s21_set_1.find(5), *std_set_1.find(5));
}

TEST(Set, InsertMany) {
  s21::set<int> s21_set_1;
  std::set<int> std_set_1 = {1, 2, 3};
  s21_set_1.insert_many(1, 2, 3);
  abc(s21_set_1, std_set_1);
}
