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

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}
void redirect(void)
{
    cr_redirect_stdout();
}

Test(my_printf, test_print_flag_X, .init = redirect_all_stdout)
{
    my_printf("Hello World %X", 11);
    cr_assert_stdout_eq_str("Hello World B", "");
}

Test(my_printf, test_print_flag_o, .init = redirect_all_stdout)
{
    my_printf("Hello World %o", 150);
    cr_assert_stdout_eq_str("Hello World 226", "");
}
