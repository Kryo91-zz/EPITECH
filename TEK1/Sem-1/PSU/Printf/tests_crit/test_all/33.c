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

Test(my_strlowcase, should_return_abcde)
{
    char string[] = "ABCDE";
    my_strlowcase(string);
    cr_assert_str_eq(string, "abcde");
}

Test(my_strlowcase, should_return_abtiretcde)
{
    char string[] = "AB-CDE";
    my_strlowcase(string);
    cr_assert_str_eq(string, "ab-cde");
}

Test(my_strcapitalize, should_return_inverse_majmin)
{
    char string[] = "ABcd";
    my_strcapitalize(string);
}