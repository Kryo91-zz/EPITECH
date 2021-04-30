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

Test(my_putstr, should_print_C_into_stdout)
{
    cr_redirect_stdout();
    my_putstr ("C");
    cr_assert_stdout_eq_str("C");
}

Test(my_putstr, should_print_BONJOUR_KARIM_into_stdout)
{
    cr_redirect_stdout();
    my_putstr ("BONJOUR KARIM");
    cr_assert_stdout_eq_str("BONJOUR KARIM");
}

Test(my_revstr, should_return_empty_str)
{
    char str[] = "";
    my_revstr(str);
    cr_assert_str_empty(str);
}