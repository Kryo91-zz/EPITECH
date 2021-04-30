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

Test(my_strncmp, should_return_minus_1) {

    char message[] = "hel";
    char message2[] = "hello";
    int n = 6;
    cr_assert_eq(my_strncmp(message, message2, n), -1);
}

Test(my_strlowcase, should_return_empty_string)
{
    char string[] = "";
    my_strlowcase(string);
    cr_assert_str_empty(string);
}

Test(my_strlowcase, should_return_a)
{
    char string[] = "A";
    my_strlowcase(string);
    cr_assert_str_eq(string, "a");
}