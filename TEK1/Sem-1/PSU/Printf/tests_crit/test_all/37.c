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

Test(my_printf, test_print_mult_flag, .init = redirect_all_stdout)
{
    my_printf("%c %d %s", 'c', 42, "baptiste");
    cr_assert_stdout_eq_str("c 42 baptiste", "");
}

Test(my_printf, test_print_mult_flag2, .init = redirect_all_stdout)
{
    my_printf("%c %d %s %s %d", 'c', 42, "baptiste", "bap", 45);
    cr_assert_stdout_eq_str("c 42 baptiste bap 45", "");
}

Test(my_printf, test_print_flag_i, .init = redirect_all_stdout)
{
    my_printf("%i", 42);
    cr_assert_stdout_eq_str("42", "");
}

Test(my_printf, test_print_test_complicated, .init = redirect_all_stdout)
{
    my_printf("%%s%%d%s%d", "lol", 42);
    cr_assert_stdout_eq_str("%s%dlol42", "");
}

Test(my_printf, test_print_test_flag_has, .init = redirect_all_stdout)
{
    my_printf("%#x", 15);
    cr_assert_stdout_eq_str("0xf", "");
}