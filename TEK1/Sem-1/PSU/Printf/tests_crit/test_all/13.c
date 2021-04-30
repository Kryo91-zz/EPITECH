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

Test(my_compute_power_rec, should_return_0_with_5)
{
    int square = 5;
    int result = my_compute_square_root(square);
    cr_assert_eq(result, 0);
}

Test(my_find_prime_sup, five_is_a_prime_number)
{
    int nb = my_find_prime_sup(-563);
}

Test(my_getnbr, test_test_test)
{
    int test2 = my_getnbr("0");
    int test3 = my_getnbr("12344532");
    int test4 = my_getnbr("-132");
    int test5 = my_getnbr("23");

    cr_assert_eq(test2, 0);
    cr_assert_eq(test3, 12344532);
    cr_assert_eq(test4, -132);
    cr_assert_eq(test5, 23);
}