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

Test (my_isneg, should_print_P2)
{
    cr_redirect_stdout();
    my_isneg(12);
    cr_assert_stdout_eq_str("P");
}

Test (my_isneg, should_print_P3)
{
    cr_redirect_stdout();
    my_isneg(54000);
    cr_assert_stdout_eq_str("P");
}

Test (my_isneg, should_print_N)
{
    cr_redirect_stdout();
    my_isneg(-20);
    cr_assert_stdout_eq_str("N");
}