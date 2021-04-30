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

Test(my_str_isprintable, test_nothin_in_string)
{
    char str[] = "";
    int result = my_str_isprintable(str);

    cr_assert_eq(result, 1);
}

Test(my_str_isprintable, test_all_printable_str)
{
    char str[] = "hello";
    int result = my_str_isprintable(str);

    cr_assert_eq(result, 1);
}

Test(my_str_isprintable, test_noprintable)
{
    char str[] = "\a";
    int result = my_str_isprintable(str);

    cr_assert_eq(result, 0);
}