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

Test(my_put_nbr, nbr_is_print3, .init = redirect)
{
    int i = -123456;
    my_put_nbr(i);
    cr_assert_stdout_eq_str("-123456", "-123456");
}

Test(my_putchar, should_print_A_into_stdout)
{
    cr_redirect_stdout();
    my_putchar('A');
    cr_assert_stdout_eq_str("A");
}

Test(my_putchar, should_print_Hello_into_stdout)
{
    cr_redirect_stdout();
    my_putchar('H');
    my_putchar('e');
    my_putchar('l');
    my_putchar('l');
    my_putchar('o');
    cr_assert_stdout_eq_str("Hello");
}