// Copyright 2024 granceti aka vsem privet and fredgran
#include <array>

#include "./s21_main_test.h"

TEST(Array, Constructors_1) {
  s21::array<int, 10> s21_array;
  EXPECT_EQ(s21_array.size(), 10);
  for (size_t i = 0; i < s21_array.size(); i++) {
    EXPECT_EQ(s21_array[i], 0);
  }
}

TEST(Array, Constructors_2) {
  s21::array<int, 5> s21_array_1 = {1, 2, 3, 4, 5};
  std::array<int, 5> std_array_1 = {1, 2, 3, 4, 5};
  EXPECT_EQ(s21_array_1.size(), std_array_1.size());
  for (size_t i = 0; i < std_array_1.size(); i++) {
    EXPECT_EQ(s21_array_1[i], std_array_1[i]);
  }
  s21::array<int, 5> s21_array_2(s21_array_1);
  std::array<int, 5> std_array_2(std_array_1);
  EXPECT_EQ(s21_array_2.size(), std_array_2.size());
  for (size_t i = 0; i < std_array_2.size(); i++) {
    EXPECT_EQ(s21_array_2[i], std_array_2[i]);
  }
  s21::array<int, 5> s21_array_3(std::move(s21_array_1));
  std::array<int, 5> std_array_3(std::move(std_array_1));
  EXPECT_EQ(s21_array_1.empty(), std_array_1.empty());
  EXPECT_EQ(s21_array_3.size(), std_array_3.size());
  for (size_t i = 0; i < std_array_3.size(); i++) {
    EXPECT_EQ(s21_array_3[i], std_array_3[i]);
  }
}

TEST(Array, Operators) {
  s21::array<int, 5> s21_array_1 = {1, 2, 3, 4, 5};
  std::array<int, 5> std_array_1 = {1, 2, 3, 4, 5};
  s21::array<int, 5> s21_array_2;
  std::array<int, 5> std_array_2;
  s21_array_2 = s21_array_1;
  std_array_2 = std_array_1;
  EXPECT_EQ(s21_array_2.size(), std_array_2.size());
  for (size_t i = 0; i < std_array_2.size(); i++) {
    EXPECT_EQ(s21_array_2[i], std_array_2[i]);
  }
  s21::array<int, 5> s21_array_3;
  std::array<int, 5> std_array_3;
  s21_array_3 = std::move(s21_array_1);
  std_array_3 = std::move(std_array_1);
  EXPECT_EQ(s21_array_1.empty(), std_array_1.empty());
  EXPECT_EQ(s21_array_3.size(), std_array_3.size());
  for (size_t i = 0; i < std_array_3.size(); i++) {
    EXPECT_EQ(s21_array_3[i], std_array_3[i]);
  }
}

TEST(Array, References) {
  s21::array<int, 5> s21_array_1 = {1, 2, 3, 4, 5};
  std::array<int, 5> std_array_1 = {1, 2, 3, 4, 5};
  for (size_t i = 0; i < std_array_1.size(); i++) {
    EXPECT_EQ(s21_array_1[i], std_array_1[i]);
    EXPECT_EQ(s21_array_1.at(i), s21_array_1.at(i));
  }
  EXPECT_THROW(s21_array_1.at(10), std::out_of_range);
}

TEST(Array, Const_References) {
  const s21::array<int, 5> s21_array_1 = {1, 2, 3, 4, 5};
  const std::array<int, 5> std_array_1 = {1, 2, 3, 4, 5};
  for (size_t i = 0; i < std_array_1.size(); i++) {
    EXPECT_EQ(s21_array_1[i], std_array_1[i]);
    EXPECT_EQ(s21_array_1.at(i), s21_array_1.at(i));
  }
  EXPECT_THROW(s21_array_1.at(10), std::out_of_range);
}

TEST(Array, Front_n_Back) {
  s21::array<int, 5> s21_array_1 = {1, 2, 3, 4, 5};
  std::array<int, 5> std_array_1 = {1, 2, 3, 4, 5};
  EXPECT_EQ(s21_array_1.front(), std_array_1.front());
  EXPECT_EQ(s21_array_1.back(), std_array_1.back());
  s21::array<float, 5> s21_array_2 = {1.1, 2.2, 3.3, 4.4, 5.5};
  std::array<float, 5> std_array_2 = {1.1, 2.2, 3.3, 4.4, 5.5};
  EXPECT_EQ(s21_array_2.front(), std_array_2.front());
  EXPECT_EQ(s21_array_2.back(), std_array_2.back());
}

TEST(Array, Data) {
  s21::array<int, 5> s21_array_1 = {1, 2, 3, 4, 5};
  s21::array<float, 5> s21_array_2 = {1.1, 2.2, 3.3, 4.4, 5.5};

  EXPECT_EQ(s21_array_1.data(), &s21_array_1[0]);
  EXPECT_EQ(s21_array_2.data(), &s21_array_2[0]);
}

TEST(Array, Begin_n_End) {
  s21::array<int, 5> s21_array_1 = {1, 2, 3, 4, 5};
  EXPECT_EQ(s21_array_1.begin(), &s21_array_1[0]);
  EXPECT_EQ(s21_array_1.end(), &s21_array_1[0] + 5);
  s21::array<float, 5> s21_array_2 = {1.1, 2.2, 3.3, 4.4, 5.5};
  EXPECT_EQ(s21_array_2.begin(), &s21_array_2[0]);
  EXPECT_EQ(s21_array_2.end(), &s21_array_2[0] + 5);
}

TEST(Array, Empty) {
  s21::array<int, 5> s21_array_1 = {1, 2, 3, 4, 5};
  EXPECT_EQ(s21_array_1.empty(), false);
}

TEST(Array, Sizes) {
  s21::array<int, 5> s21_array_1 = {1, 2, 3, 4, 5};
  std::array<int, 5> std_array_1 = {1, 2, 3, 4, 5};
  EXPECT_EQ(s21_array_1.size(), std_array_1.size());
  EXPECT_EQ(s21_array_1.max_size(), std_array_1.max_size());
  s21::array<float, 5> s21_array_2 = {1.1, 2.2, 3.3, 4.4, 5.5};
  std::array<float, 5> std_array_2 = {1.1, 2.2, 3.3, 4.4, 5.5};
  EXPECT_EQ(s21_array_2.size(), std_array_2.size());
  EXPECT_EQ(s21_array_2.max_size(), std_array_2.max_size());
}

TEST(Array, Swap) {
  s21::array<int, 5> s21_array_1 = {1, 2, 3, 4, 5};
  std::array<int, 5> std_array_1 = {1, 2, 3, 4, 5};
  s21::array<int, 5> s21_array_2 = {10, 20, 30, 40, 50};
  std::array<int, 5> std_array_2 = {10, 20, 30, 40, 50};
  s21_array_2.swap(s21_array_1);
  std_array_2.swap(std_array_1);
  EXPECT_EQ(s21_array_2.size(), std_array_2.size());
  for (size_t i = 0; i < std_array_2.size(); i++) {
    EXPECT_EQ(s21_array_1[i], std_array_1[i]);
    EXPECT_EQ(s21_array_2[i], std_array_2[i]);
  }
}
