/*
** EPITECH PROJECT, 2020
** criterion_ex01.c
** File description:
** ex01
*/

#include "../string.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(empty_string, empty_stringt)
{
    string_t s;
    string_init(&s, "I'm a pokemon");
    int i = empty(&s);
    cr_assert_eq(i, 0);
    string_destroy(&s);
}

Test(empty_string, empty_string_m2)
{
    string_t s;
    string_init(&s, "");
    int i = empty(&s);
    cr_assert_eq(i, 1);
    string_destroy(&s);
}