/*
** EPITECH PROJECT, 2019
**  criterion_test
** File description:
** yo
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdarg.h>
#include "../../inc/my.h"

Test(my_compute_power_rec, should_return_0)
{
    cr_redirect_stdout();
    int number = 10;
    int power = -4;
    int result = my_compute_power_rec(number, power);
    cr_assert_eq(0, result);
}

Test(my_compute_power_rec, should_return_2_power_32)
{
    cr_redirect_stdout();
    int number = 2;
    int power = 32;
    int result = my_compute_power_rec(number, power);
    cr_assert_eq(0, result);
}

Test(my_compute_power_rec, should_return_3_power_6)
{
    cr_redirect_stdout();
    int number = 3;
    int power = 6;
    int result = my_compute_power_rec(number, power);
    cr_assert_eq(729, result);
}