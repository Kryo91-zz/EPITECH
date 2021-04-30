/*
** EPITECH PROJECT, 2019
** Desktop
** File description:
** test_factorial.c
*/

#include <criterion/criterion.h>

int my_compute_factorial(int factor);

Test(my_compute_factorial_rec, should_return_factorial)
{
    cr_assert_eq(my_compute_factorial(3), 6);
}