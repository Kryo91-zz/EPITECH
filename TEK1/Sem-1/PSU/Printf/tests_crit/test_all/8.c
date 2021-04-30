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

Test(my_strlen, test_on_empty_string)
{
    int result = my_strlen("");
    cr_assert_eq(result, 0);
}

Test(my_strlen, test_on_normal_string)
{
    int result = my_strlen("Hello");
    cr_assert_eq(result, 5);
}

Test(my_strlen, test_on_full_sentence)
{
    int result = my_strlen("Hello World!");
    cr_assert_eq(result, 12);
}