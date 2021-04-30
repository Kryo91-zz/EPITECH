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

Test(my_strcapitalize, should_return_inverse_minmaj)
{
    char string[] = "aBcDEfg";
    my_strcapitalize(string);
}

Test(my_strcapitalize, should_return_inverse_nothing)
{
    char string[] = "";
    my_strcapitalize(string);
    cr_assert_str_eq(string, "");
}

Test(my_printf, test_print_str, .init = redirect_all_stdout)
{
    my_printf("str");
    cr_assert_stdout_eq_str("str", "");
}
