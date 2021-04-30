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

Test(my_putchar, should_print_non_printable_char_into_stdout)
{
    cr_redirect_stdout();
    my_putchar('\a');
    cr_assert_stdout_eq_str("\a");
}

Test(my_putstr, should_print_ABC_into_stdout)
{
    cr_redirect_stdout();
    my_putstr ("ABC");
    cr_assert_stdout_eq_str("ABC");
}

Test(my_putstr, should_print_non_printable_char_into_stdout)
{
    cr_redirect_stdout();
    my_putstr ("\a");
    cr_assert_stdout_eq_str("\a");
}