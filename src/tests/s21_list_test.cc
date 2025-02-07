// Copyright 2024 granceti aka vsem privet and fredgran
#include <list>

#include "./s21_main_test.h"

TEST(List, Constructors_1) {
  s21::list<int> s21_list;
  std::list<int> std_list;
  EXPECT_EQ(s21_list.empty(), std_list.empty());
}

TEST(List, Constructors_2) {
  s21::list<int> s21_list_1(6);
  std::list<int> std_list_1(6);
  EXPECT_EQ(s21_list_1.size(), std_list_1.size());
  s21::list<int> s21_list_2(15);
  std::list<int> std_list_2(15);
  EXPECT_EQ(s21_list_2.size(), std_list_2.size());
  s21::list<int> s21_list_3(0);
  std::list<int> std_list_3(0);
  EXPECT_EQ(s21_list_3.size(), std_list_3.size());
}

TEST(List, Constructors_3) {
  s21::list<int> s21_list_1 = {1, 5, 10};
  std::list<int> std_list_1 = {1, 5, 10};
  EXPECT_EQ(s21_list_1.size(), std_list_1.size());
  EXPECT_EQ(s21_list_1.front(), std_list_1.front());
  EXPECT_EQ(s21_list_1.back(), std_list_1.back());
  s21::list<int> s21_list_2(s21_list_1);
  std::list<int> std_list_2(std_list_1);
  EXPECT_EQ(s21_list_2.size(), std_list_2.size());
  EXPECT_EQ(s21_list_2.front(), std_list_2.front());
  EXPECT_EQ(s21_list_2.back(), std_list_2.back());
  s21::list<int> s21_list_3(std::move(s21_list_1));
  std::list<int> std_list_3(std::move(std_list_1));
  EXPECT_EQ(s21_list_3.size(), std_list_3.size());
  EXPECT_EQ(s21_list_3.front(), std_list_3.front());
  EXPECT_EQ(s21_list_3.back(), std_list_3.back());
  EXPECT_EQ(s21_list_1.empty(), std_list_1.empty());
}

TEST(List, Operators) {
  s21::list<int> s21_list_1 = {1, 5, 10};
  std::list<int> std_list_1 = {1, 5, 10};
  s21::list<int> s21_list_2;
  std::list<int> std_list_2;
  s21_list_2 = s21_list_1;
  std_list_2 = std_list_1;
  EXPECT_EQ(s21_list_2.size(), std_list_2.size());
  EXPECT_EQ(s21_list_2.front(), std_list_2.front());
  EXPECT_EQ(s21_list_2.back(), std_list_2.back());
  s21::list<int> s21_list_3;
  std::list<int> std_list_3;
  s21_list_3 = std::move(s21_list_1);
  std_list_3 = std::move(std_list_1);
  EXPECT_EQ(s21_list_3.size(), std_list_3.size());
  EXPECT_EQ(s21_list_3.front(), std_list_3.front());
  EXPECT_EQ(s21_list_3.back(), std_list_3.back());
  EXPECT_EQ(s21_list_1.empty(), std_list_1.empty());
}

TEST(List, Front_n_Back) {
  s21::list<int> s21_list_1 = {1, 5, 10};
  std::list<int> std_list_1 = {1, 5, 10};
  EXPECT_EQ(s21_list_1.front(), std_list_1.front());
  EXPECT_EQ(s21_list_1.back(), std_list_1.back());
  s21_list_1.push_back(0);
  std_list_1.push_back(0);
  s21_list_1.pop_front();
  std_list_1.pop_front();
  EXPECT_EQ(s21_list_1.front(), std_list_1.front());
  EXPECT_EQ(s21_list_1.back(), std_list_1.back());
}

TEST(List, Begin_n_End) {
  s21::list<int> s21_list_1 = {1, 5, 10};
  std::list<int> std_list_1 = {1, 5, 10};
  s21::list<int>::iterator iter_s21;
  std::list<int>::iterator iter_std;
  iter_s21 = s21_list_1.begin();
  iter_std = std_list_1.begin();
  iter_s21++;
  iter_std++;
  EXPECT_EQ(*iter_s21, *iter_std);
  iter_s21++;
  iter_std++;
  EXPECT_EQ(*iter_s21, *iter_std);
  iter_s21 = s21_list_1.end();
  iter_std = std_list_1.end();
  iter_s21--;
  iter_std--;
  EXPECT_EQ(*iter_s21, *iter_std);
  // s21::list<int>::const_iterator cIter_s21;
  // std::list<int>::const_iterator cIter_std;
  // cIter_s21 = s21_list_1.begin();
  // cIter_std = std_list_1.begin();
  // EXPECT_EQ(*cIter_s21, *cIter_std);
  // cIter_s21 = s21_list_1.cbegin();
  // cIter_std = std_list_1.cbegin();
  // EXPECT_EQ(*cIter_s21, *cIter_std);
  // cIter_s21 = s21_list_1.end();
  // cIter_std = std_list_1.end();
  // EXPECT_EQ(*cIter_s21, *cIter_std);
  // cIter_s21 = s21_list_1.cend();
  // cIter_std = std_list_1.cend();
  // EXPECT_EQ(*cIter_s21, *cIter_std);
}

TEST(List, Empty) {
  s21::list<int> s21_list_1;
  std::list<int> std_list_1;
  EXPECT_EQ(s21_list_1.empty(), std_list_1.empty());
  s21_list_1.push_front(1);
  std_list_1.push_front(1);
  EXPECT_EQ(s21_list_1.empty(), std_list_1.empty());
}

TEST(List, Sizes) {
  s21::list<int> s21_list_1(40);
  std::list<int> std_list_1(40);
  EXPECT_EQ(s21_list_1.size(), std_list_1.size());
  EXPECT_EQ(s21_list_1.max_size(), std_list_1.max_size());
  // s21_list_1.resize(20);
  // std_list_1.resize(20);
  // EXPECT_EQ(s21_list_1.size(), std_list_1.size());
  // EXPECT_EQ(s21_list_1.max_size(), std_list_1.max_size());
}

TEST(List, Clear) {
  s21::list<int> s21_list_1 = {1, 5, 10};
  std::list<int> std_list_1 = {1, 5, 10};
  s21_list_1.clear();
  std_list_1.clear();
  EXPECT_EQ(s21_list_1.empty(), std_list_1.empty());
  s21_list_1.clear();
  std_list_1.clear();
  EXPECT_EQ(s21_list_1.empty(), std_list_1.empty());
}

TEST(List, Insert) {
  s21::list<int> s21_list_1 = {1, 5, 10};
  std::list<int> std_list_1 = {1, 5, 10};
  s21::list<int>::iterator iter_s21 = s21_list_1.end();
  std::list<int>::iterator iter_std = std_list_1.end();
  s21_list_1.insert(iter_s21, 15);
  std_list_1.insert(iter_std, 15);
  EXPECT_EQ(s21_list_1.size(), std_list_1.size());
  iter_s21 = s21_list_1.begin();
  iter_std = std_list_1.begin();
  s21_list_1.insert(iter_s21, 7);
  std_list_1.insert(iter_std, 7);
  EXPECT_EQ(s21_list_1.size(), std_list_1.size());
  iter_s21 = s21_list_1.begin();
  iter_std = std_list_1.begin();
  for (; iter_std != std_list_1.end(); ++iter_s21, ++iter_std) {
    EXPECT_EQ(*iter_s21, *iter_std);
  }
}

TEST(List, Erase) {
  s21::list<int> s21_list_1 = {1, 1, 5, 10};
  std::list<int> std_list_1 = {1, 1, 5, 10};
  s21::list<int>::iterator iter_s21;
  std::list<int>::iterator iter_std;
  iter_s21 = s21_list_1.end();
  iter_std = std_list_1.end();
  iter_s21--;
  iter_std--;
  iter_s21--;
  iter_std--;
  s21_list_1.erase(iter_s21);
  std_list_1.erase(iter_std);
  iter_s21 = s21_list_1.end();
  iter_std = std_list_1.end();
  iter_s21--;
  iter_std--;
  s21_list_1.erase(iter_s21);
  std_list_1.erase(iter_std);
  iter_s21 = s21_list_1.end();
  iter_std = std_list_1.end();
  iter_s21--;
  iter_std--;
  EXPECT_EQ(s21_list_1.size(), std_list_1.size());
  EXPECT_EQ(*iter_s21, *iter_std);
  iter_s21 = s21_list_1.end();
  iter_std = std_list_1.end();
  EXPECT_THROW(s21_list_1.erase(iter_s21), std::out_of_range);
}

TEST(List, Push) {
  s21::list<int> s21_list_1 = {1, 5, 10};
  std::list<int> std_list_1 = {1, 5, 10};
  s21_list_1.push_back(40);
  std_list_1.push_back(40);
  s21_list_1.push_front(52);
  std_list_1.push_front(52);
  EXPECT_EQ(s21_list_1.front(), std_list_1.front());
  EXPECT_EQ(s21_list_1.back(), std_list_1.back());
}

TEST(List, Pop) {
  s21::list<int> s21_list_1 = {1, 5, 10, 15};
  std::list<int> std_list_1 = {1, 5, 10, 15};
  s21_list_1.pop_back();
  std_list_1.pop_back();
  s21_list_1.pop_front();
  std_list_1.pop_front();
  EXPECT_EQ(s21_list_1.front(), std_list_1.front());
  EXPECT_EQ(s21_list_1.back(), std_list_1.back());
  s21_list_1.pop_back();
  std_list_1.pop_back();
  s21_list_1.pop_back();
  std_list_1.pop_back();
  EXPECT_EQ(s21_list_1.empty(), std_list_1.empty());
}

TEST(List, Swap) {
  s21::list<int> s21_list_1 = {1, 5, 10, 15};
  std::list<int> std_list_1 = {1, 5, 10, 15};
  s21::list<int> s21_list_2;
  std::list<int> std_list_2;
  s21_list_2.swap(s21_list_1);
  std_list_2.swap(std_list_1);
  EXPECT_EQ(s21_list_1.empty(), std_list_1.empty());
  EXPECT_EQ(s21_list_2.front(), std_list_2.front());
  EXPECT_EQ(s21_list_2.back(), std_list_2.back());
  EXPECT_EQ(s21_list_2.size(), std_list_2.size());
}

TEST(List, Merge) {
  s21::list<int> s21_list_1 = {1, 5, 10, 15};
  std::list<int> std_list_1 = {1, 5, 10, 15};
  s21::list<int> s21_list_2 = {2, 7, 12};
  std::list<int> std_list_2 = {2, 7, 12};
  s21_list_1.merge(s21_list_2);
  std_list_1.merge(std_list_2);
  EXPECT_EQ(s21_list_1.size(), std_list_1.size());
  EXPECT_EQ(s21_list_2.empty(), std_list_2.empty());
  s21::list<int>::iterator iter_s21;
  std::list<int>::iterator iter_std;
  iter_s21 = s21_list_1.begin();
  iter_std = std_list_1.begin();
  for (; iter_std != std_list_1.end(); ++iter_s21, ++iter_std) {
    EXPECT_EQ(*iter_s21, *iter_std);
  }
}

TEST(List, Splice) {
  s21::list<int> s21_list_1 = {1, 5, 10, 15};
  std::list<int> std_list_1 = {1, 5, 10, 15};
  s21::list<int> s21_list_2 = {2, 7, 12};
  std::list<int> std_list_2 = {2, 7, 12};
  s21::list<int>::iterator iter_s21 = s21_list_1.begin();
  std::list<int>::iterator iter_std = std_list_1.begin();
  s21_list_1.splice(iter_s21, s21_list_2);
  std_list_1.splice(iter_std, std_list_2);
  iter_s21 = s21_list_1.begin();
  iter_std = std_list_1.begin();
  EXPECT_EQ(s21_list_1.size(), std_list_1.size());
  EXPECT_EQ(s21_list_2.empty(), std_list_2.empty());
  for (; iter_std != std_list_1.end(); ++iter_s21, ++iter_std) {
    EXPECT_EQ(*iter_s21, *iter_std);
  }
  s21::list<int> s21_list_3 = {1, 5, 10, 15};
  std::list<int> std_list_3 = {1, 5, 10, 15};
  s21::list<int> s21_list_4 = {2, 7, 12};
  std::list<int> std_list_4 = {2, 7, 12};
  iter_s21 = s21_list_3.begin();
  iter_std = std_list_3.begin();
  iter_s21++;
  iter_std++;
  s21_list_3.splice(iter_s21, s21_list_4);
  std_list_3.splice(iter_std, std_list_4);
  iter_s21 = s21_list_3.begin();
  iter_std = std_list_3.begin();
  EXPECT_EQ(s21_list_3.size(), std_list_3.size());
  EXPECT_EQ(s21_list_4.empty(), std_list_4.empty());
  for (; iter_std != std_list_3.end(); ++iter_s21, ++iter_std) {
    EXPECT_EQ(*iter_s21, *iter_std);
  }
  s21::list<int> s21_list_5 = {1, 5, 10, 15};
  std::list<int> std_list_5 = {1, 5, 10, 15};
  s21::list<int> s21_list_6 = {2, 7, 12};
  std::list<int> std_list_6 = {2, 7, 12};
  iter_s21 = s21_list_5.end();
  iter_std = std_list_5.end();
  s21_list_5.splice(iter_s21, s21_list_6);
  std_list_5.splice(iter_std, std_list_6);
  iter_s21 = s21_list_5.begin();
  iter_std = std_list_5.begin();
  EXPECT_EQ(s21_list_5.size(), std_list_5.size());
  EXPECT_EQ(s21_list_6.empty(), std_list_6.empty());
  for (; iter_std != std_list_5.end(); ++iter_s21, ++iter_std) {
    EXPECT_EQ(*iter_s21, *iter_std);
  }
}

TEST(List, Reverse) {
  s21::list<int> s21_list_1 = {1, 5, 10, 15};
  std::list<int> std_list_1 = {1, 5, 10, 15};
  s21_list_1.reverse();
  std_list_1.reverse();
  s21::list<int>::iterator iter_s21;
  std::list<int>::iterator iter_std;
  iter_s21 = s21_list_1.begin();
  iter_std = std_list_1.begin();
  for (; iter_std != std_list_1.end(); ++iter_s21, ++iter_std) {
    EXPECT_EQ(*iter_s21, *iter_std);
  }
  s21::list<int> s21_list_2;
  std::list<int> std_list_2;
  s21_list_2.reverse();
  std_list_2.reverse();
  EXPECT_EQ(s21_list_2.empty(), std_list_2.empty());
  s21::list<int> s21_list_3 = {1};
  std::list<int> std_list_3 = {1};
  s21_list_3.reverse();
  std_list_3.reverse();
  EXPECT_EQ(s21_list_3.front(), std_list_3.front());
  EXPECT_EQ(s21_list_3.back(), std_list_3.back());
}

TEST(List, Unique) {
  s21::list<int> s21_list_1 = {1, 1, 5, 5};
  std::list<int> std_list_1 = {1, 1, 5, 5};
  s21_list_1.unique();
  std_list_1.unique();
  EXPECT_EQ(s21_list_1.size(), std_list_1.size());
  EXPECT_EQ(s21_list_1.front(), std_list_1.front());
  EXPECT_EQ(s21_list_1.back(), std_list_1.back());
  s21::list<int> s21_list_2 = {1, 5, 15};
  std::list<int> std_list_2 = {1, 5, 15};
  s21_list_2.unique();
  std_list_2.unique();
  EXPECT_EQ(s21_list_2.size(), std_list_2.size());
  EXPECT_EQ(s21_list_2.front(), std_list_2.front());
  EXPECT_EQ(s21_list_2.back(), std_list_2.back());
  s21::list<int> s21_list_3;
  std::list<int> std_list_3;
  s21_list_3.unique();
  std_list_3.unique();
  EXPECT_EQ(s21_list_3.empty(), std_list_3.empty());
}

TEST(List, Sort) {
  s21::list<int> s21_list_1 = {5, 1, 3, 31, 7, 7, 8, 1, 7, 8, 33, 35};
  std::list<int> std_list_1 = {5, 1, 3, 31, 7, 7, 8, 1, 7, 8, 33, 35};
  s21_list_1.sort();
  std_list_1.sort();
  s21::list<int>::iterator iter_s21 = s21_list_1.begin();
  std::list<int>::iterator iter_std = std_list_1.begin();
  EXPECT_EQ(s21_list_1.size(), std_list_1.size());
  for (; iter_std != std_list_1.end(); ++iter_s21, ++iter_std) {
    EXPECT_EQ(*iter_s21, *iter_std);
  }
  s21::list<int> s21_list_2 = {1, 2, 3, 4, 5};
  std::list<int> std_list_2 = {1, 2, 3, 4, 5};
  s21_list_2.sort();
  std_list_2.sort();
  iter_s21 = s21_list_2.begin();
  iter_std = std_list_2.begin();
  EXPECT_EQ(s21_list_2.size(), std_list_2.size());
  for (; iter_std != std_list_2.end(); ++iter_s21, ++iter_std) {
    EXPECT_EQ(*iter_s21, *iter_std);
  }
  s21::list<int> s21_list_3;
  std::list<int> std_list_3;
  s21_list_3.sort();
  std_list_3.sort();
  EXPECT_EQ(s21_list_3.empty(), std_list_3.empty());
  s21::list<int> s21_list_4 = {1};
  std::list<int> std_list_4 = {1};
  s21_list_4.sort();
  std_list_4.sort();
  iter_s21 = s21_list_4.begin();
  iter_std = std_list_4.begin();
  EXPECT_EQ(s21_list_4.size(), std_list_4.size());
  for (; iter_std != std_list_4.end(); ++iter_s21, ++iter_std) {
    EXPECT_EQ(*iter_s21, *iter_std);
  }
}

TEST(List, Insert_Many) {
  s21::list<int> s21_list = {1, 2, 3, 4};
  s21::list<int> s21_list_res = {1, 5, 6, 7, 2, 3, 4};
  s21::list<int>::iterator iter_s21 = s21_list.begin();
  iter_s21++;
  s21_list.insert_many(iter_s21, 5, 6, 7);
  iter_s21 = s21_list.begin();
  s21::list<int>::iterator iter_s21_res = s21_list_res.begin();
  EXPECT_EQ(s21_list.size(), s21_list_res.size());
  for (; iter_s21 != s21_list_res.end(); ++iter_s21, ++iter_s21_res) {
    EXPECT_EQ(*iter_s21, *iter_s21_res);
  }
  iter_s21 = s21_list.begin();
  s21_list.insert_many(iter_s21, 10, 20);
  s21_list_res.push_front(10);
  s21_list_res.push_front(20);
  iter_s21 = s21_list.begin();
  iter_s21_res = s21_list_res.begin();
  EXPECT_EQ(s21_list.size(), s21_list_res.size());
  for (; iter_s21 != s21_list_res.end(); ++iter_s21, ++iter_s21_res) {
    EXPECT_EQ(*iter_s21, *iter_s21_res);
  }
  iter_s21 = s21_list.end();
  s21_list.insert_many(iter_s21, 40, 50);
  s21_list_res.push_back(40);
  s21_list_res.push_back(50);
  iter_s21 = s21_list.begin();
  iter_s21_res = s21_list_res.begin();
  EXPECT_EQ(s21_list.size(), s21_list_res.size());
  for (; iter_s21 != s21_list_res.end(); ++iter_s21, ++iter_s21_res) {
    EXPECT_EQ(*iter_s21, *iter_s21_res);
  }
}

TEST(List, Insert_Many_Front_n_Back) {
  s21::list<int> s21_list = {1, 2, 3};
  s21::list<int> s21_list_res = {5, 6, 7, 1, 2, 3};
  s21_list.insert_many_front(7, 6, 5);
  s21::list<int>::iterator iter_s21 = s21_list.begin();
  s21::list<int>::iterator iter_s21_res = s21_list_res.begin();
  EXPECT_EQ(s21_list.size(), s21_list_res.size());
  for (; iter_s21 != s21_list_res.end(); ++iter_s21, ++iter_s21_res) {
    EXPECT_EQ(*iter_s21, *iter_s21_res);
  }
  s21_list.insert_many_back(10, 20, 30);
  s21_list_res.push_back(10);
  s21_list_res.push_back(20);
  s21_list_res.push_back(30);
  iter_s21 = s21_list.begin();
  iter_s21_res = s21_list_res.begin();
  for (; iter_s21 != s21_list_res.end(); ++iter_s21, ++iter_s21_res) {
    EXPECT_EQ(*iter_s21, *iter_s21_res);
  }
}
