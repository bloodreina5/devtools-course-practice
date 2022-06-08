// Copyright 2022 Kuklin Andrey

#include <gtest/gtest.h>

#include "include/modified_stack.h"

TEST(kuklin_andrey_modified_stack,
     can_create_modified_stack_with_default_param) {
  ASSERT_NO_THROW(ModifiedStack());
}

TEST(kuklin_andrey_modified_stack,
     can_create_modified_stack_with_correct_size) {
  ASSERT_NO_THROW(ModifiedStack(5));
}

TEST(kuklin_andrey_modified_stack, can_check_modified_stack_is_empty) {
  ModifiedStack mst;

  ASSERT_NO_THROW(mst.Empty());
}

TEST(kuklin_andrey_modified_stack, new_modified_stack_is_empty) {
  ModifiedStack mst;

  ASSERT_TRUE(mst.Empty());
}

TEST(kuklin_andrey_modified_stack,
     cant_create_modified_stack_with_not_correct_size) {
  ASSERT_ANY_THROW(ModifiedStack(-5));
}

TEST(kuklin_andrey_modified_stack, can_create_modified_stack_with_copy_constr) {
  ModifiedStack copy;

  ASSERT_NO_THROW(ModifiedStack(copy));
}

TEST(kuklin_andrey_modified_stack,
     created_modified_stack_with_copy_constr_equal_source_stack) {
  ModifiedStack sourceSt;

  sourceSt.Push(3);
  sourceSt.Push(6);
  sourceSt.Push(7);
  sourceSt.Push(9);

  ModifiedStack copySt(sourceSt);

  while (!sourceSt.Empty()) {
    ASSERT_EQ(copySt.Top(), sourceSt.Top());

    copySt.Pop();
    sourceSt.Pop();
  }
}

TEST(kuklin_andrey_modified_stack, can_push_in_modified_stack) {
  ModifiedStack mst;

  ASSERT_NO_THROW(mst.Push(1));
}

TEST(kuklin_andrey_modified_stack, can_check_size_modified_stack) {
  ModifiedStack mst;

  ASSERT_NO_THROW(mst.Size());
}

TEST(kuklin_andrey_modified_stack, push_change_modified_stack_size) {
  ModifiedStack mst;

  std::size_t startSize = mst.Size();
  mst.Push(1);
  std::size_t finalSize = mst.Size();

  ASSERT_NE(startSize, finalSize);
}

TEST(kuklin_andrey_modified_stack, size_modified_stack_correct_after_push) {
  ModifiedStack mst;

  std::size_t startSize = mst.Size();
  mst.Push(1);
  std::size_t finalSize = mst.Size();

  ASSERT_EQ(startSize, finalSize - 1);
}

TEST(kuklin_andrey_modified_stack, can_check_top_elem_of_modified_stack) {
  ModifiedStack mst;
  mst.Push(1);

  ASSERT_NO_THROW(mst.Top());
}

TEST(kuklin_andrey_modified_stack,
     cant_check_top_elem_of_empty_modified_stack) {
  ModifiedStack mst;

  ASSERT_ANY_THROW(mst.Top());
}

TEST(kuklin_andrey_modified_stack, top_elem_of_modified_stack_correct) {
  ModifiedStack mst;

  mst.Push(1234);
  mst.Push(5678);

  ASSERT_EQ(mst.Top(), 5678);
}

TEST(kuklin_andrey_modified_stack, can_delete_top_elem_of_modified_stack) {
  ModifiedStack mst;

  mst.Push(1);

  ASSERT_NO_THROW(mst.Pop());
}

TEST(kuklin_andrey_modified_stack,
     cant_delete_top_elem_of_empty_modified_stack) {
  ModifiedStack mst;

  ASSERT_ANY_THROW(mst.Pop());
}

TEST(kuklin_andrey_modified_stack,
     top_elem_of_modified_stack_correct_after_pop) {
  ModifiedStack mst;

  mst.Push(12);
  mst.Push(34);
  mst.Pop();

  ASSERT_EQ(mst.Top(), 12);
}

TEST(kuklin_andrey_modified_stack, can_check_modified_stack_is_full) {
  ModifiedStack mst;

  ASSERT_NO_THROW(mst.Full());
}

TEST(kuklin_andrey_modified_stack, check_modified_stack_full_is_correct) {
  ModifiedStack mst(1);

  mst.Push(2);
  ASSERT_TRUE(mst.Full());
}

TEST(kuklin_andrey_modified_stack, can_push_in_full_modified_stack) {
  ModifiedStack mst(1);

  mst.Push(2);

  ASSERT_NO_THROW(mst.Push(7));
}

TEST(kuklin_andrey_modified_stack, push_in_full_modified_stack_is_correct) {
  ModifiedStack mst(2);

  mst.Push(2);
  mst.Push(7);

  ASSERT_EQ(mst.Top(), 7);
}

TEST(kuklin_andrey_modified_stack, can_take_min_elem_modified_stack) {
  ModifiedStack mst;

  mst.Push(2);

  ASSERT_NO_THROW(mst.MinElem());
}

TEST(kuklin_andrey_modified_stack, cant_take_min_elem_empty_modified_stack) {
  ModifiedStack mst;

  ASSERT_ANY_THROW(mst.MinElem());
}

TEST(kuklin_andrey_modified_stack, min_elem_modified_stack_is_correct) {
  ModifiedStack mst;

  mst.Push(7);
  mst.Push(2);
  mst.Push(5);

  ASSERT_EQ(mst.MinElem(), 2);
}

TEST(kuklin_andrey_modified_stack, can_clear_modified_stack) {
  ModifiedStack mst;

  ASSERT_NO_THROW(mst.Clear());
}

TEST(kuklin_andrey_modified_stack, clearing_modified_stack_set_zero_size) {
  ModifiedStack mst;
  mst.Clear();

  ASSERT_EQ(mst.Size(), static_cast<std::size_t>(0));
}

TEST(kuklin_andrey_modified_stack, can_compare_modified_stacks) {
  ModifiedStack mstFirst, mstSecond;

  ASSERT_NO_THROW(mstFirst == mstSecond);
}

TEST(kuklin_andrey_modified_stack, equal_modified_stacks_is_equal) {
  ModifiedStack mstFirst, mstSecond;

  mstFirst.Push(5);
  mstSecond.Push(5);

  ASSERT_TRUE(mstFirst == mstSecond);
}

TEST(kuklin_andrey_modified_stack, can_compare_not_eq_modified_stacks) {
  ModifiedStack mstFirst, mstSecond;

  mstFirst.Push(2);

  ASSERT_NO_THROW(mstFirst != mstSecond);
}

TEST(kuklin_andrey_modified_stack, modified_stacks_with_diff_sizes_not_equal) {
  ModifiedStack mstFirst, mstSecond;

  mstFirst.Push(5);

  ASSERT_TRUE(mstFirst != mstSecond);
}

TEST(kuklin_andrey_modified_stack,
     modified_stacks_with_different_elements_not_equal) {
  ModifiedStack mstFirst, mstSecond;

  mstFirst.Push(5);
  mstFirst.Push(6);
  mstSecond.Push(5);
  mstSecond.Push(4);

  ASSERT_TRUE(mstFirst != mstSecond);
}

TEST(kuklin_andrey_modified_stack, can_equate_modified_stacks) {
  ModifiedStack mstFirst, mstSecond;

  ASSERT_NO_THROW(mstFirst = mstSecond);
}

TEST(kuklin_andrey_modified_stack,
     can_assign_modified_stack_with_different_maxsize) {
  ModifiedStack mstFirst(3), mstSecond(5);

  ASSERT_NO_THROW(mstSecond = mstFirst);
}

TEST(kuklin_andrey_modified_stack, equated_modified_stack_equal_source) {
  ModifiedStack mstFirst, mstSecond;

  mstFirst.Push(3);
  mstFirst.Push(6);
  mstFirst.Push(7);
  mstFirst.Push(9);

  mstSecond = mstFirst;

  while (!mstFirst.Empty()) {
    ASSERT_EQ(mstFirst.Top(), mstSecond.Top());

    mstFirst.Pop();
    mstSecond.Pop();
  }
}
