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

Test(my_strupcase, should_return_ABCDE)
{
    char string[] = "abcde";
    my_strupcase(string);
    cr_assert_str_eq(string, "ABCDE");
}

Test(my_strupcase, should_return_ABCtiretCDE)
{
    char string[] = "ab-cde";
    my_strupcase(string);
    cr_assert_str_eq(string, "AB-CDE");
}

Test(my_strstr, should_find_empty_string_in_empty_string)
{
    char first[] = "";
    char second[] = "";
    char *result = my_strstr(first, second);
    cr_assert_eq(result, first);
}