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

Test(my_printf, test_print_flag_perc, .init = redirect_all_stdout)
{
    my_printf("%%");
    cr_assert_stdout_eq_str("%", "");
}

Test(my_printf, test_print_flag_n, .init = redirect_all_stdout)
{
    my_printf("Hello World %n");
    cr_assert_stdout_eq_str("Hello World 12", "");
}

Test(my_printf, test_print_flag_x, .init = redirect_all_stdout)
{
    my_printf("Hello World %x", 11);
    cr_assert_stdout_eq_str("Hello World b", "");
}