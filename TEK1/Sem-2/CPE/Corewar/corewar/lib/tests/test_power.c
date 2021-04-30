/*
** EPITECH PROJECT, 2019
** Desktop
** File description:
** test_power.c
*/

#include <criterion/criterion.h>

int my_compute_power(int nb, int p);

Test(my_compute_power_rec, should_return_nine)
{
    cr_assert_eq(my_compute_power(3, 3), 27);
}