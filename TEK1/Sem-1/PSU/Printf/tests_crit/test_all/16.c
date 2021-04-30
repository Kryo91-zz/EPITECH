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

Test(my_is_prime, it_is_not_prime_number)
{
    int nb = my_is_prime(172872);
    cr_assert_eq(nb, 0);
}

Test(my_is_prime, five_is_a_prime_number)
{
    int nb = my_is_prime(-563);
}

Test (my_isneg, should_print_P)
{
    cr_redirect_stdout();
    my_isneg(0);
    cr_assert_stdout_eq_str("P");
}