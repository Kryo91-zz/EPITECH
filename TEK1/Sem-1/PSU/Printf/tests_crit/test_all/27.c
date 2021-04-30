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

Test(my_str_isnum, return_0_nummaj)
{
    int i = 0;
    char str[] = "12345SDFGX";

    i = my_str_isnum(str);
    cr_assert_eq(i, 0);
}

Test(my_str_isnum, return_1_numspace)
{
    int i = 0;
    char str[] = "12345 123456";

    i = my_str_isnum(str);
}

Test(my_str_isnum, return_0_maj_space)
{
    int i = 0;
    char str[] = "dzdzce CZEVRE";

    i = my_str_isnum(str);
    cr_assert_eq(i, 0);
}