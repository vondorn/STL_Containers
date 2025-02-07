// Copyright 2024 granceti aka vsem privet and fredgran

#include "./s21_main_test.h"

void abc(s21::multiset<int> ex, s21::multiset<int> res) {
  EXPECT_EQ(ex.size(), res.size());
  EXPECT_EQ(ex.empty(), res.empty());
  auto it = ex.begin();
  auto wo = res.begin();
  for (; it != ex.end() && wo != res.end(); it++, wo++) {
    EXPECT_EQ(*it, *wo);
  }
}

TEST(Multiset, Constructors_1) {
  s21::multiset<int> ex;
  EXPECT_EQ(ex.empty(), true);
  s21::multiset<int> ex2 = {1, 2, 3};
  EXPECT_EQ(ex2.empty(), false);
  ex = std::move(ex2);
  EXPECT_EQ(ex2.empty(), true);
  EXPECT_EQ(ex.empty(), false);
}

TEST(Multiset, Constructors_2) {
  s21::multiset<int> ex = {1, 2, 3, 4, 5};
  s21::multiset<int> res;
  res.insert(1);
  res.insert(2);
  res.insert(3);
  res.insert(4);
  res.insert(5);
  abc(ex, res);
  s21::multiset<int> ex2 = {1, 1, 3, 1, 5};
  s21::multiset<int> res2;
  res2.insert(1);
  res2.insert(1);
  res2.insert(3);
  res2.insert(1);
  res2.insert(5);
  abc(ex2, res2);
}

TEST(Multiset, Size) {
  s21::multiset<int> ex = {1, 2, 3, 4, 5};
  EXPECT_EQ(ex.size(), 5);
  s21::multiset<int> ex2;
  EXPECT_EQ(ex2.size(), 0);
}

TEST(Multiset, Clear) {
  s21::multiset<int> ex = {1, 2, 3, 4, 5};
  s21::multiset<int> wo;
  ex.clear();
  abc(ex, wo);
}

TEST(Multiset, Erase) {
  s21::multiset<int> ex = {1, 1, 2, 2, 3, 3, 4};
  s21::multiset<int> wo = {1, 2, 2, 3, 3, 4};
  ex.erase(ex.begin());
  abc(ex, wo);
}

TEST(Multiset, Count) {
  s21::multiset<int> ex = {1, 1, 2, 2, 3, 3, 4};
  EXPECT_EQ(ex.count(2), 2);
}

TEST(Multiset, Bound) {
  s21::multiset<int> ex = {1, 1, 2, 2, 3, 3, 3, 4};
  EXPECT_EQ(*ex.lower_bound(3), *(ex.begin() + 4));
  EXPECT_EQ(*ex.upper_bound(3), *(ex.end() - 1));
  EXPECT_EQ(*ex.equal_range(3).first, *(ex.begin() + 4));
  EXPECT_EQ(*ex.equal_range(3).second, *(ex.end() - 1));
}

TEST(Multiset, Swap) {
  s21::multiset<int> ex = {1, 1, 2, 2, 3, 3, 3, 4};
  s21::multiset<int> ex2 = {1, 1, 2, 2, 3, 3, 3, 4};
  s21::multiset<int> wo = {5, 6, 7, 8, 9};
  s21::multiset<int> wo2 = {5, 6, 7, 8, 9};
  ex.swap(wo);
  abc(wo, ex2);
  abc(wo2, ex);
}

TEST(Multiset, Merge) {
  s21::multiset<int> ex = {1, 1, 2, 2, 3, 3, 3, 4};
  s21::multiset<int> wo = {5, 6, 7, 8, 9};
  s21::multiset<int> res = {1, 1, 2, 2, 3, 3, 3, 4, 5, 6, 7, 8, 9};
  ex.merge(wo);
  abc(res, ex);
}

TEST(Multiset, InsertMany) {
  s21::multiset<int> ex;
  s21::multiset<int> wo = {1, 2, 3};
  ex.insert_many(1, 2, 3);
  abc(ex, wo);
}
