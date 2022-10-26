#include "tmatrix.h"

#include <gtest.h>

TEST(TDynamicMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TDynamicMatrix<int> m(5));
}

TEST(TDynamicMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TDynamicMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TDynamicMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TDynamicMatrix<int> m(-5));
}

TEST(TDynamicMatrix, can_create_copied_matrix)
{
  TDynamicMatrix<int> m(5);

  ASSERT_NO_THROW(TDynamicMatrix<int> m1(m));
}

TEST(TDynamicMatrix, copied_matrix_is_equal_to_source_one)
{
    TDynamicMatrix<int>v1(10);
    v1[0][0] = 2;
    v1[4][3] = -8;
    TDynamicMatrix<int>v2(v1);
    EXPECT_EQ(v1, v2);
}

TEST(TDynamicMatrix, copied_matrix_has_its_own_memory)
{
    TDynamicMatrix<int>v1(3);
    v1[0][0] = 1;
    v1[2][1] = 6;
    TDynamicMatrix<int>v2(v1);
    v2[0][0] = -1;
    EXPECT_NE(v1, v2);
}

TEST(TDynamicMatrix, can_get_size)
{
    TDynamicMatrix<int>v1(3);
    int res = v1.size();
    EXPECT_EQ(3, res);
}

TEST(TDynamicMatrix, can_set_and_get_element)
{
    TDynamicMatrix<int>v1(10);
    v1[3][2] = 10;
    v1[3][2] = v1[3][2] - 3;
    EXPECT_EQ(v1[3][2], 7);
}

TEST(TDynamicMatrix, throws_when_set_element_with_negative_index)
{
    TDynamicMatrix<int>v1(3);
    EXPECT_ANY_THROW(v1[-1][0] = 1);
}

TEST(TDynamicMatrix, throws_when_set_element_with_too_large_index)
{
    TDynamicMatrix<int>v1(10);
    EXPECT_ANY_THROW(v1[10][0] = 1);
}

TEST(TDynamicMatrix, can_assign_matrix_to_itself)
{
    TDynamicMatrix<int>v1(3);
    EXPECT_NO_THROW(v1 = v1);
}

TEST(TDynamicMatrix, can_assign_matrices_of_equal_size)
{
    TDynamicMatrix<int>v1(5);
    TDynamicMatrix<int>v2(5);
    EXPECT_NO_THROW(v1 = v2);
}

TEST(TDynamicMatrix, assign_operator_change_matrix_size)
{
    TDynamicMatrix<int>v1(5);
    TDynamicMatrix<int>v2(4);
    v1 = v2;
    EXPECT_EQ(v1.size(), 4);
}

TEST(TDynamicMatrix, can_assign_matrices_of_different_size)
{
    TDynamicMatrix<int>v1(3);
    TDynamicMatrix<int>v2(4);
    EXPECT_NO_THROW(v2 = v1);
}

TEST(TDynamicMatrix, compare_equal_matrices_return_true)
{
    TDynamicMatrix<int>v1(2);
    TDynamicMatrix<int>v2(v1);
    EXPECT_EQ(v1 == v2, true);
}

TEST(TDynamicMatrix, compare_matrix_with_itself_return_true)
{
    TDynamicMatrix<int>v1(2);
    EXPECT_EQ(v1 == v1, true);
}

TEST(TDynamicMatrix, matrices_with_different_size_are_not_equal)
{
    TDynamicMatrix<int>v1(3);
    TDynamicMatrix<int>v2(4);
    EXPECT_EQ(v1 == v2, false);
}

TEST(TDynamicMatrix, can_add_matrices_with_equal_size)
{
    TDynamicMatrix<int>v1(3);
    TDynamicMatrix<int>v2(3);
    v1[1][1] = 1;
    v2[1][1] = 2;
    TDynamicMatrix<int>ans = v1 + v2;
    TDynamicMatrix<int>res(3);
    res[1][1] = 3;
    EXPECT_EQ(ans, res);
}

TEST(TDynamicMatrix, cant_add_matrices_with_not_equal_size)
{
    TDynamicMatrix<int>v1(5);
    TDynamicMatrix<int>v2(6);
    EXPECT_ANY_THROW(v1 + v2);
}

TEST(TDynamicMatrix, can_subtract_matrices_with_equal_size)
{
    TDynamicMatrix<int>v1(3);
    TDynamicMatrix<int>v2(3);
    v1[1][1] = 5;
    v2[1][1] = 3;
    TDynamicMatrix<int>ans = v1 - v2;
    TDynamicMatrix<int>res(3);
    res[1][1] = 2;
    EXPECT_EQ(ans, res);
}

TEST(TDynamicMatrix, cant_subtract_matrixes_with_not_equal_size)
{
    TDynamicMatrix<int>v1(5);
    TDynamicMatrix<int>v2(6);
    EXPECT_ANY_THROW(v1 - v2);
}

