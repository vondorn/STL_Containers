// Copyright 2024 granceti aka vsem privet and fredgran
#include <queue>

#include "./s21_main_test.h"

TEST(Queue, Constructors_1) {
  s21::queue<int> s21_queue;
  std::queue<int> std_queue;
  EXPECT_EQ(s21_queue.empty(), std_queue.empty());
}

TEST(Queue, Constructors_2) {
  s21::queue<int> s21_queue_1 = {1, 5, 10};
  std::queue<int> std_queue_1;
  std_queue_1.push(1);
  std_queue_1.push(5);
  std_queue_1.push(10);
  EXPECT_EQ(s21_queue_1.size(), std_queue_1.size());
  EXPECT_EQ(s21_queue_1.front(), std_queue_1.front());
  EXPECT_EQ(s21_queue_1.back(), std_queue_1.back());
  s21::queue<int> s21_queue_2(s21_queue_1);
  std::queue<int> std_queue_2(std_queue_1);
  EXPECT_EQ(s21_queue_2.size(), std_queue_2.size());
  EXPECT_EQ(s21_queue_2.front(), std_queue_2.front());
  EXPECT_EQ(s21_queue_2.back(), std_queue_2.back());
  s21::queue<int> s21_queue_3(std::move(s21_queue_1));
  std::queue<int> std_queue_3(std::move(std_queue_1));
  EXPECT_EQ(s21_queue_3.size(), std_queue_3.size());
  EXPECT_EQ(s21_queue_3.front(), std_queue_3.front());
  EXPECT_EQ(s21_queue_3.back(), std_queue_3.back());
  EXPECT_EQ(s21_queue_1.empty(), std_queue_1.empty());
}

TEST(Queue, Operators) {
  s21::queue<int> s21_queue_1 = {1, 5, 10};
  std::queue<int> std_queue_1;
  std_queue_1.push(1);
  std_queue_1.push(5);
  std_queue_1.push(10);
  s21::queue<int> s21_queue_2;
  std::queue<int> std_queue_2;
  s21_queue_2.push(1);
  std_queue_2.push(1);
  s21_queue_2 = s21_queue_1;
  std_queue_2 = std_queue_1;
  EXPECT_EQ(s21_queue_2.size(), std_queue_2.size());
  EXPECT_EQ(s21_queue_2.front(), std_queue_2.front());
  EXPECT_EQ(s21_queue_2.back(), std_queue_2.back());
  s21::queue<int> s21_queue_3;
  std::queue<int> std_queue_3;
  s21_queue_3 = std::move(s21_queue_1);
  std_queue_3 = std::move(std_queue_1);
  EXPECT_EQ(s21_queue_3.size(), std_queue_3.size());
  EXPECT_EQ(s21_queue_3.front(), std_queue_3.front());
  EXPECT_EQ(s21_queue_3.back(), std_queue_3.back());
  EXPECT_EQ(s21_queue_1.empty(), std_queue_1.empty());
}

TEST(Queue, Front_n_Back) {
  s21::queue<int> s21_queue_1 = {1, 5, 10};
  std::queue<int> std_queue_1;
  std_queue_1.push(1);
  std_queue_1.push(5);
  std_queue_1.push(10);
  EXPECT_EQ(s21_queue_1.front(), std_queue_1.front());
  EXPECT_EQ(s21_queue_1.back(), std_queue_1.back());
  s21_queue_1.push(0);
  std_queue_1.push(0);
  s21_queue_1.pop();
  std_queue_1.pop();
  EXPECT_EQ(s21_queue_1.front(), std_queue_1.front());
  EXPECT_EQ(s21_queue_1.back(), std_queue_1.back());
}

TEST(Queue, Empty) {
  s21::queue<int> s21_queue_1;
  std::queue<int> std_queue_1;
  EXPECT_EQ(s21_queue_1.empty(), std_queue_1.empty());
  s21_queue_1.push(1);
  std_queue_1.push(1);
  EXPECT_EQ(s21_queue_1.empty(), std_queue_1.empty());
}

TEST(Queue, Size) {
  s21::queue<int> s21_queue_1;
  std::queue<int> std_queue_1;
  EXPECT_EQ(s21_queue_1.size(), std_queue_1.size());
  s21_queue_1.push(1);
  std_queue_1.push(1);
  EXPECT_EQ(s21_queue_1.size(), std_queue_1.size());
}

TEST(Queue, Push) {
  s21::queue<int> s21_queue_1;
  std::queue<int> std_queue_1;
  s21_queue_1.push(40);
  std_queue_1.push(40);
  s21_queue_1.push(52);
  std_queue_1.push(52);
  EXPECT_EQ(s21_queue_1.front(), std_queue_1.front());
  EXPECT_EQ(s21_queue_1.back(), std_queue_1.back());
}

TEST(Queue, Pop) {
  s21::queue<int> s21_queue_1 = {1, 5, 10, 15};
  std::queue<int> std_queue_1;
  std_queue_1.push(1);
  std_queue_1.push(5);
  std_queue_1.push(10);
  std_queue_1.push(15);
  s21_queue_1.pop();
  std_queue_1.pop();
  s21_queue_1.pop();
  std_queue_1.pop();
  EXPECT_EQ(s21_queue_1.front(), std_queue_1.front());
  EXPECT_EQ(s21_queue_1.back(), std_queue_1.back());
  s21_queue_1.pop();
  std_queue_1.pop();
  s21_queue_1.pop();
  std_queue_1.pop();
  EXPECT_EQ(s21_queue_1.empty(), std_queue_1.empty());
}

TEST(Queue, Swap) {
  s21::queue<int> s21_queue_1 = {1, 5, 10, 15};
  std::queue<int> std_queue_1;
  std_queue_1.push(1);
  std_queue_1.push(5);
  std_queue_1.push(10);
  std_queue_1.push(15);
  s21::queue<int> s21_queue_2;
  std::queue<int> std_queue_2;
  s21_queue_2.swap(s21_queue_1);
  std_queue_2.swap(std_queue_1);
  EXPECT_EQ(s21_queue_1.empty(), std_queue_1.empty());
  EXPECT_EQ(s21_queue_2.front(), std_queue_2.front());
  EXPECT_EQ(s21_queue_2.back(), std_queue_2.back());
  EXPECT_EQ(s21_queue_2.size(), std_queue_2.size());
}

TEST(Queue, Insert_Many_Back) {
  s21::queue<int> s21_queue = {1, 2, 3};
  s21::queue<int> s21_queue_res = {1, 2, 3};
  s21_queue.insert_many_back(10, 20, 30);
  s21_queue_res.push(10);
  s21_queue_res.push(20);
  s21_queue_res.push(30);
  EXPECT_EQ(s21_queue.size(), s21_queue_res.size());
  for (size_t i = 0; i < 6; i++) {
    EXPECT_EQ(s21_queue.front(), s21_queue_res.front());
    s21_queue.pop();
    s21_queue_res.pop();
  }
}
