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

Test (my_strncpy, test_on_empty_string)
{
    char *dest = "";
    char *src = "";
    int n = 1;
    char *result = my_strncpy(dest, src, n);
    cr_assert_str_eq(result, src);
}

Test (my_strncpy, test_on_normal_string)
{
    char dest[6];
    char src[] = "Hello";
    int n = 5;
    char *result = my_strncpy(dest, src, n);
    cr_assert_str_eq(result, src);
}

Test (my_strncpy, test_n_is_null)
{
    char dest[6];
    char src[] = "Hello";
    int n = 0;
    char *result = my_strncpy(dest, src, n);
}