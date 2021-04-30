/*
** EPITECH PROJECT, 2019
** criterion_test
** File description:
** yo
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdarg.h>
#include "../../inc/my.h"

Test(my_printf, test_print_test_flag_has_max, .init = redirect_all_stdout)
{
    my_printf("%#X", 15);
    cr_assert_stdout_eq_str("0XF", "");
}

Test(my_printf, test_print_test_flag_has_oct, .init = redirect_all_stdout)
{
    my_printf("%#o", 15);
    cr_assert_stdout_eq_str("017", "");
}

Test(my_printf, test_print_test_flag_long, .init = redirect_all_stdout)
{
    my_printf("%l %l", 15, 42);
    cr_assert_stdout_eq_str("15 42", "");
}

Test(my_printf, test_print_test_flag_unsi, .init = redirect_all_stdout)
{
    my_printf("%u %u %u %u", 15, 42, 25456, 726868725);
    cr_assert_stdout_eq_str("15 42 25456 726868725", "");
}

Test(my_printf, test_print_test_flag_bina, .init = redirect_all_stdout)
{
    my_printf("%b", 12);
    cr_assert_stdout_eq_str("1100", "");
}