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

Test(my_str_islower, should_return_0_only_non_alpha_chars)
{
    int ret = my_str_islower("{((((2484204924");
    cr_assert_eq(ret, 0);
}

Test(my_str_islower, should_return_1_empty)
{
    int ret = my_str_islower("");
    cr_assert_eq(ret, 1);
}

Test(my_str_isnum, return_1)
{
    int i = 0;
    char str[] = "23456754323456787654";
    i = my_str_isnum(str);
}