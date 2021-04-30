/*
** EPITECH PROJECT, 2019
** Desktop
** File description:
** test_sqrt.c
*/

#include <criterion/criterion.h>

int my_compute_square_root(int nb);

Test(my_compute_square_root, should_return_five)
{
    cr_assert_eq(my_compute_square_root(25), 5);
}

Test(my_compute_square_root, should_return_minus_one_one)
{
    cr_assert_eq(my_compute_square_root(42), -1);
}

Test(my_compute_square_root, should_return_minus_one_two)
{
    cr_assert_eq(my_compute_square_root(0), -1);
}