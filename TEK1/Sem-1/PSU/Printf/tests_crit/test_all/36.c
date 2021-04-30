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

Test(my_printf, test_print_str_perc, .init = redirect_all_stdout)
{
    my_printf("%s", "str");
    cr_assert_stdout_eq_str("str", "");
}

Test(my_printf, test_print_num, .init = redirect_all_stdout)
{
    my_printf("%d", 42);
    cr_assert_stdout_eq_str("42", "");
}

Test(my_printf, test_print_char, .init = redirect_all_stdout)
{
    my_printf("%c", 'c');
    cr_assert_stdout_eq_str("c", "");
}

Test(my_printf, test_print_multiple_char, .init = redirect_all_stdout)
{
    my_printf("%c %s %d", 'c', "lol", 42);
    cr_assert_stdout_eq_str("c lol 42", "");
}

Test(my_printf, test_print_invalid, .init = redirect_all_stdout)
{
    my_printf("%G%g%F");
    cr_assert_stdout_eq_str("%G%g%F", "");
}