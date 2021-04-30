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

Test(my_swap, should_reverse_character_dif)
{
    int a[] = {16564668};
    int b[] = {15424957};
    my_swap(a, b);
    cr_assert_eq(*a, 15424957);
    cr_assert_eq(*b , 16564668);
}

Test(my_strupcase, should_return_empty_string)
{
    char string[] = "";
    my_strupcase(string);
    cr_assert_str_empty(string);
}

Test(my_strupcase, should_return_A)
{
    char string[] = "a";
    my_strupcase(string);
    cr_assert_str_eq(string, "A");
}