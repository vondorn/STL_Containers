// Copyright 2024 granceti aka vsem privet and fredgran
#include <stack>

#include "./s21_main_test.h"

TEST(Stack, Constructors_1) {
  s21::stack<int> s21_stack;
  std::stack<int> std_stack;
  EXPECT_EQ(s21_stack.empty(), std_stack.empty());
}

TEST(Stack, Constructors_2) {
  s21::stack<int> s21_stack_1 = {1, 5, 10};
  std::stack<int> std_stack_1;
  std_stack_1.push(1);
  std_stack_1.push(5);
  std_stack_1.push(10);
  EXPECT_EQ(s21_stack_1.size(), std_stack_1.size());
  EXPECT_EQ(s21_stack_1.top(), std_stack_1.top());
  s21::stack<int> s21_stack_2(s21_stack_1);
  std::stack<int> std_stack_2(std_stack_1);
  EXPECT_EQ(s21_stack_2.size(), std_stack_2.size());
  EXPECT_EQ(s21_stack_2.top(), std_stack_2.top());
  s21::stack<int> s21_stack_3(std::move(s21_stack_1));
  std::stack<int> std_stack_3(std::move(std_stack_1));
  EXPECT_EQ(s21_stack_3.size(), std_stack_3.size());
  EXPECT_EQ(s21_stack_3.top(), std_stack_3.top());
  EXPECT_EQ(s21_stack_1.empty(), std_stack_1.empty());
}

TEST(Stack, Operators) {
  s21::stack<int> s21_stack_1 = {1, 5, 10};
  std::stack<int> std_stack_1;
  std_stack_1.push(1);
  std_stack_1.push(5);
  std_stack_1.push(10);
  s21::stack<int> s21_stack_2;
  std::stack<int> std_stack_2;
  s21_stack_2.push(1);
  std_stack_2.push(1);
  s21_stack_2 = s21_stack_1;
  std_stack_2 = std_stack_1;
  EXPECT_EQ(s21_stack_2.size(), std_stack_2.size());
  EXPECT_EQ(s21_stack_2.top(), std_stack_2.top());
  s21::stack<int> s21_stack_3;
  std::stack<int> std_stack_3;
  s21_stack_3 = std::move(s21_stack_1);
  std_stack_3 = std::move(std_stack_1);
  EXPECT_EQ(s21_stack_3.size(), std_stack_3.size());
  EXPECT_EQ(s21_stack_3.top(), std_stack_3.top());
  EXPECT_EQ(s21_stack_1.empty(), std_stack_1.empty());
}

TEST(Stack, Top) {
  s21::stack<int> s21_stack_1 = {1, 5, 10};
  std::stack<int> std_stack_1;
  std_stack_1.push(1);
  std_stack_1.push(5);
  std_stack_1.push(10);
  EXPECT_EQ(s21_stack_1.top(), std_stack_1.top());
  s21_stack_1.push(0);
  std_stack_1.push(0);
  s21_stack_1.pop();
  std_stack_1.pop();
  EXPECT_EQ(s21_stack_1.top(), std_stack_1.top());
}

TEST(Stack, Empty) {
  s21::stack<int> s21_stack_1;
  std::stack<int> std_stack_1;
  EXPECT_EQ(s21_stack_1.empty(), std_stack_1.empty());
  s21_stack_1.push(1);
  std_stack_1.push(1);
  EXPECT_EQ(s21_stack_1.empty(), std_stack_1.empty());
}

TEST(Stack, Size) {
  s21::stack<int> s21_stack_1;
  std::stack<int> std_stack_1;
  EXPECT_EQ(s21_stack_1.size(), std_stack_1.size());
  s21_stack_1.push(1);
  std_stack_1.push(1);
  EXPECT_EQ(s21_stack_1.size(), std_stack_1.size());
}

TEST(Stack, Push) {
  s21::stack<int> s21_stack_1;
  std::stack<int> std_stack_1;
  s21_stack_1.push(40);
  std_stack_1.push(40);
  s21_stack_1.push(52);
  std_stack_1.push(52);
  EXPECT_EQ(s21_stack_1.top(), std_stack_1.top());
}

TEST(Stack, Pop) {
  s21::stack<int> s21_stack_1 = {1, 5, 10, 15};
  std::stack<int> std_stack_1;
  std_stack_1.push(1);
  std_stack_1.push(5);
  std_stack_1.push(10);
  std_stack_1.push(15);
  s21_stack_1.pop();
  std_stack_1.pop();
  s21_stack_1.pop();
  std_stack_1.pop();
  EXPECT_EQ(s21_stack_1.top(), std_stack_1.top());
  s21_stack_1.pop();
  std_stack_1.pop();
  s21_stack_1.pop();
  std_stack_1.pop();
  EXPECT_EQ(s21_stack_1.empty(), std_stack_1.empty());
}

TEST(Stack, Swap) {
  s21::stack<int> s21_stack_1 = {1, 5, 10, 15};
  std::stack<int> std_stack_1;
  std_stack_1.push(1);
  std_stack_1.push(5);
  std_stack_1.push(10);
  std_stack_1.push(15);
  s21::stack<int> s21_stack_2;
  std::stack<int> std_stack_2;
  s21_stack_2.swap(s21_stack_1);
  std_stack_2.swap(std_stack_1);
  EXPECT_EQ(s21_stack_1.empty(), std_stack_1.empty());
  EXPECT_EQ(s21_stack_2.top(), std_stack_2.top());
  EXPECT_EQ(s21_stack_2.size(), std_stack_2.size());
}

TEST(Stack, Insert_Many_Back) {
  s21::stack<int> s21_stack = {1, 2, 3};
  s21::stack<int> s21_stack_res = {1, 2, 3};
  s21_stack.insert_many_back(10, 20, 30);
  s21_stack_res.push(10);
  s21_stack_res.push(20);
  s21_stack_res.push(30);
  EXPECT_EQ(s21_stack.size(), s21_stack_res.size());
  for (size_t i = 0; i < 6; i++) {
    EXPECT_EQ(s21_stack.top(), s21_stack_res.top());
    s21_stack.pop();
    s21_stack_res.pop();
  }
}
