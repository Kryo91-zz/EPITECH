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

Test (my_isneg, should_print_N2)
{
    cr_redirect_stdout();
    my_isneg(-50000);
    cr_assert_stdout_eq_str("N");
}

Test(my_put_nbr, nbr_is_print, .init = redirect)
{
    int i = 53423;
    my_put_nbr(i);
    cr_assert_stdout_eq_str("53423", "53423");
}

Test(my_put_nbr, nbr_is_print2, .init = redirect)
{
    int i = 0;
    my_put_nbr(i);
    cr_assert_stdout_eq_str("0", "0");
}

Test(, nbr_is_print3, .init = redirect)
{
    int i = 2147483648;
    my_put_nbr(i);
    cr_assert_stdout_eq_str("2147483648", "2147483648");
}