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

Test(my_is_prime, zero_is_not_a_prime_number)
{
    int nb = my_is_prime(0);
    cr_assert_eq(nb, 0);
}

Test(my_is_prime, one_is_not_a_prime_number)
{
    int nb = my_is_prime(1);
    cr_assert_eq(nb, 0);
}

Test(my_is_prime, it_is_a_prime_number)
{
    int nb = my_is_prime(7789);
}