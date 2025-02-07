// Copyright 2024 granceti aka vsem privet and fredgran
#include <map>

#include "./s21_main_test.h"

void abc(s21::map<int, char> s21, std::map<int, char> std) {
  EXPECT_EQ(s21.size(), std.size());
  for (size_t i = 1; i <= std.size(); i++) {
    EXPECT_EQ(s21[i], std[i]);
  }
}

TEST(Map, Constructors_1) {
  s21::map<int, char> s21_map;
  std::map<int, char> std_map;
  EXPECT_EQ(s21_map.empty(), std_map.empty());
}

TEST(Map, Constructors_2) {
  s21::map<int, char> s21_map_1 = {{1, 'c'}, {2, 'b'}, {3, 'a'}};
  std::map<int, char> std_map_1 = {{1, 'c'}, {2, 'b'}, {3, 'a'}};
  s21_map_1[4] = 'a';
  std_map_1[4] = 'a';
  abc(s21_map_1, std_map_1);
  EXPECT_EQ(s21_map_1.size(), std_map_1.size());
  s21::map<int, char> s21_map_2(s21_map_1);
  std::map<int, char> std_map_2(std_map_1);
  abc(s21_map_2, std_map_2);
  EXPECT_EQ(s21_map_2.size(), std_map_2.size());
  s21::map<int, char> s21_map_3(std::move(s21_map_1));
  std::map<int, char> std_map_3(std::move(std_map_1));
  abc(s21_map_3, std_map_3);
  EXPECT_EQ(s21_map_1.empty(), std_map_1.empty());
  EXPECT_EQ(s21_map_3.size(), std_map_3.size());
}

TEST(Map, Operators) {
  s21::map<int, char> s21_map_1 = {{1, 'c'}, {2, 'b'}, {3, 'a'}};
  std::map<int, char> std_map_1 = {{1, 'c'}, {2, 'b'}, {3, 'a'}};
  s21::map<int, char> s21_map_2;
  s21_map_2 = s21_map_1;
  std::map<int, char> std_map_2;
  std_map_2 = std_map_1;
  abc(s21_map_2, std_map_2);
  EXPECT_EQ(s21_map_2.size(), std_map_2.size());
  s21::map<int, char> s21_map_3;
  s21_map_3 = std::move(s21_map_1);
  std::map<int, char> std_map_3;
  std_map_3 = std::move(std_map_1);
  abc(s21_map_3, std_map_3);
  EXPECT_EQ(s21_map_1.empty(), std_map_1.empty());
  EXPECT_EQ(s21_map_3.size(), std_map_3.size());
}

TEST(Map, References) {
  s21::map<int, char> s21_map_1 = {{1, 'c'}, {2, 'b'}, {3, 'a'}};
  std::map<int, char> std_map_1 = {{1, 'c'}, {2, 'b'}, {3, 'a'}};
  for (size_t i = 1; i <= std_map_1.size(); i++) {
    EXPECT_EQ(s21_map_1[i], std_map_1[i]);
    EXPECT_EQ(s21_map_1.at(i), s21_map_1.at(i));
  }
  EXPECT_THROW(s21_map_1.at(10), std::out_of_range);
}

TEST(Map, Empty) {
  s21::map<int, char> s21_map_1;
  std::map<int, char> std_map_1;
  EXPECT_EQ(s21_map_1.empty(), s21_map_1.empty());
  s21_map_1[4] = 'a';
  std_map_1[4] = 'a';
  EXPECT_EQ(s21_map_1.empty(), s21_map_1.empty());
}

TEST(Map, Sizes) {
  s21::map<int, char> s21_map_1 = {{1, 'c'}, {2, 'b'}, {3, 'a'}};
  std::map<int, char> std_map_1 = {{1, 'c'}, {2, 'b'}, {3, 'a'}};
  EXPECT_EQ(s21_map_1.size(), s21_map_1.size());
  EXPECT_EQ(s21_map_1.max_size(), s21_map_1.max_size());
  s21::map<int, char> s21_map_2;
  std::map<int, char> std_map_2;
  EXPECT_EQ(s21_map_2.size(), s21_map_2.size());
  EXPECT_EQ(s21_map_2.max_size(), s21_map_2.max_size());
}

TEST(Map, Clear) {
  s21::map<int, char> s21_map_1 = {{1, 'c'}, {2, 'b'}, {3, 'a'}};
  std::map<int, char> std_map_1 = {{1, 'c'}, {2, 'b'}, {3, 'a'}};
  s21_map_1.clear();
  std_map_1.clear();
  EXPECT_EQ(s21_map_1.empty(), s21_map_1.empty());
  s21_map_1.clear();
  std_map_1.clear();
  EXPECT_EQ(s21_map_1.empty(), s21_map_1.empty());
}

TEST(Map, Insert) {
  s21::map<int, char> s21_map_1;
  std::map<int, char> std_map_1;
  s21_map_1.insert(std::make_pair(1, 'A'));
  std_map_1.insert(std::make_pair(1, 'A'));
  s21_map_1.insert(2, 'B');
  std_map_1.insert(std::make_pair(2, 'B'));
  abc(s21_map_1, std_map_1);
  s21_map_1.insert_or_assign(1, 'E');
  s21_map_1.insert_or_assign(3, 'C');
  std_map_1.erase(std_map_1.begin());
  std_map_1.insert(std::make_pair(1, 'E'));
  std_map_1.insert(std::make_pair(3, 'C'));
  abc(s21_map_1, std_map_1);
}

TEST(Map, Swap) {
  s21::map<int, char> s21_map_1 = {{1, 'c'}, {2, 'b'}, {3, 'a'}};
  std::map<int, char> std_map_1 = {{1, 'c'}, {2, 'b'}, {3, 'a'}};
  s21::map<int, char> s21_map_2 = {{1, 'G'}};
  std::map<int, char> std_map_2 = {{1, 'G'}};
  s21_map_1.swap(s21_map_2);
  std_map_1.swap(std_map_2);
  abc(s21_map_1, std_map_1);
  abc(s21_map_2, std_map_2);
}

TEST(Map, Contains) {
  s21::map<int, char> s21_map_1 = {{1, 'c'}, {2, 'b'}, {3, 'a'}};
  EXPECT_EQ(s21_map_1.contains(1), true);
  EXPECT_EQ(s21_map_1.contains(4), false);
}

TEST(Map, Erase) {
  s21::map<int, char> s21_map_1 = {{1, 'c'}, {2, 'b'}, {3, 'a'}, {4, 'e'}};
  std::map<int, char> std_map_1 = {{1, 'c'}, {2, 'b'}, {3, 'a'}, {4, 'e'}};
  s21::map<int, char>::iterator iter_s21;
  std::map<int, char>::iterator iter_std;
  iter_s21 = s21_map_1.end();
  iter_std = std_map_1.end();
  iter_s21--;
  iter_std--;
  iter_s21--;
  iter_std--;
  s21_map_1.erase(iter_s21);
  std_map_1.erase(iter_std);
  iter_s21 = s21_map_1.end();
  iter_std = std_map_1.end();
  iter_s21--;
  iter_std--;
  s21_map_1.erase(iter_s21);
  std_map_1.erase(iter_std);
  iter_s21 = s21_map_1.end();
  iter_std = std_map_1.end();
  iter_s21--;
  iter_std--;
  EXPECT_EQ(s21_map_1.size(), std_map_1.size());
  EXPECT_EQ(*iter_s21, *iter_std);
  iter_s21 = s21_map_1.end();
  iter_std = std_map_1.end();
  // EXPECT_THROW(s21_map_1.erase(iter_s21), std::out_of_range);
}

TEST(Map, Begin_n_End) {
  s21::map<int, char> s21_map_1 = {{1, 'c'}, {2, 'b'}, {3, 'a'}};
  std::map<int, char> std_map_1 = {{1, 'c'}, {2, 'b'}, {3, 'a'}};
  s21::map<int, char>::iterator iter_s21;
  std::map<int, char>::iterator iter_std;
  iter_s21 = s21_map_1.begin();
  iter_std = std_map_1.begin();
  iter_s21++;
  iter_std++;
  EXPECT_EQ(*iter_s21, *iter_std);
  iter_s21++;
  iter_std++;
  EXPECT_EQ(*iter_s21, *iter_std);
  iter_s21 = s21_map_1.end();
  iter_std = std_map_1.end();
  iter_s21--;
  iter_std--;
  EXPECT_EQ(*iter_s21, *iter_std);
}

TEST(Map, Merge) {
  s21::map<int, char> s21_map_1 = {{1, 'a'}, {4, 'd'}, {2, 'b'}};
  s21::map<int, char> s21_map_2 = {{3, 'c'}, {5, 'e'}};
  s21_map_1.merge(s21_map_2);
  std::map<int, char> std_map_1 = {{1, 'a'}, {4, 'd'}, {2, 'b'}};
  std::map<int, char> std_map_2 = {{3, 'c'}, {5, 'e'}};
  std_map_1.merge(std_map_2);
  abc(s21_map_1, std_map_1);
  EXPECT_EQ(s21_map_2.empty(), std_map_2.empty());
}

TEST(Map, InsertMany) {
  s21::map<int, char> s21_map_1;
  std::map<int, char> std_map_1 = {{1, 'c'}, {2, 'b'}, {3, 'a'}};
  s21_map_1.insert_many(std::make_pair(1, 'c'), std::make_pair(2, 'b'),
                        std::make_pair(3, 'a'));
  abc(s21_map_1, std_map_1);
}
