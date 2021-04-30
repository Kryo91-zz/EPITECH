/*
** EPITECH PROJECT, 2019
** Desktop
** File description:
** test_prime.c
*/

#include <criterion/criterion.h>

int my_is_prime(int nb);

int my_find_prime_sup(int nb);

Test(my_is_prime, should_return_zero)
{
    cr_assert_eq(my_is_prime(7), 0);
}

Test(my_is_prime, my_is_prime_should_return_one)
{
    cr_assert_eq(my_is_prime(6), 1);
}

Test(my_find_prime_sup, my_find_prime_sup_should_return_7)
{
    cr_assert_eq(my_find_prime_sup(6), 7);
}