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

Test(my_str_isprintable, test_with_space)
{
    char str[] = "hello world";
    int result = my_str_isprintable(str);

    cr_assert_eq(result, 1);
}

Test(my_swap, should_reverse_character)
{
    int a[] = {1};
    int b[] = {2};
    my_swap(a, b);
    cr_assert_eq(*a, 2);
    cr_assert_eq(*b , 1);
}

Test(my_swap, should_reverse_character_eq)
{
    int a[] = {1};
    int b[] = {1};
    my_swap(a, b);
    cr_assert_eq(*a, 1);
    cr_assert_eq(*b , 1);
}