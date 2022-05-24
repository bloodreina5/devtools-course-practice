// Copyright 2022 Frolov Gleb

#include <gtest/gtest.h>
#include <string>
#include "include/regular_expressions.h"

TEST(Text_for_regexp, Can_create_default_object) {
  ASSERT_NO_THROW(Text_for_regexp text);
}

TEST(Text_for_regexp, Can_create_object_with_parameter) {
  Text_for_regexp text("qwer");

  ASSERT_EQ(text.Get_text(), "qwer");
}

TEST(Text_for_regexp, Can_search_regexp_1) {
  Text_for_regexp text("qwer tyui asdf ghjk");

  ASSERT_EQ(text.Search_for_regexp("q"), "qwer");
}

TEST(Text_for_regexp, Can_search_regexp_2) {
  Text_for_regexp text("qwer tyui asdf ghjk");

  ASSERT_EQ(text.Search_for_regexp("qw"), "qwer");
}

TEST(Text_for_regexp, Can_search_regexp_3) {
  Text_for_regexp text("qwer tyui asdf ghjk");

  ASSERT_EQ(text.Search_for_regexp("qwt"), "Not found");
}

TEST(Text_for_regexp, Can_search_regexp_4) {
  Text_for_regexp text("qwer tyui asdf ghjk");

  ASSERT_EQ(text.Search_for_regexp("t"), "tyui");
}


TEST(Text_for_regexp, Can_search_regexp_5) {
  Text_for_regexp text("qwer tyui asdf ghjk");

  ASSERT_EQ(text.Search_for_regexp("ty"), "tyui");
}

TEST(Text_for_regexp, Can_search_regexp_6) {
  Text_for_regexp text("qwer tyui asdf ghjk");

  ASSERT_EQ(text.Search_for_regexp("ui"), "tyui");
}

TEST(Text_for_regexp, Can_search_regexp_7) {
  Text_for_regexp text("qwer tyui asdf ghjk");

  ASSERT_EQ(text.Search_for_regexp("g"), "ghjk");
}

TEST(Text_for_regexp, Can_search_regexp_8) {
  Text_for_regexp text("qwer tyui asdf ghjk");

  ASSERT_EQ(text.Search_for_regexp("k"), "ghjk");
}

TEST(Text_for_regexp, Can_search_regexp_9) {
  Text_for_regexp text("qwer tyui qw00 ghjk");

  ASSERT_EQ(text.Search_for_regexp("w"), "qwer|qw00");
}

TEST(Text_for_regexp, Can_search_regexp_10) {
  Text_for_regexp text("qwer tyui qw00 ghjk");

  ASSERT_EQ(text.Search_for_regexp("wr"), "Not found");
}
