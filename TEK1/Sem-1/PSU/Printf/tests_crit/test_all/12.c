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

Test(my_compute_power_rec, should_return_2401)
{
    cr_redirect_stdout();
    int number = -7;
    int power = 4;
    int result = my_compute_power_rec(number, power);
    cr_assert_eq(2401, result);
}

Test(my_compute_power_rec, should_return_square_root_of_64)
{
    int square = 64;
    int result = my_compute_square_root(square);
    cr_assert_eq(result, 8);
}

Test(my_compute_power_rec, should_return_0_with_0)
{
    int square = 0;
    int result = my_compute_square_root(square);
    cr_assert_eq(result, 0);
}