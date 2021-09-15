/*
** EPITECH PROJECT, 2020
** criterion_ex01.c
** File description:
** ex01
*/

#include "../string.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(at_string, at_stringt)
{
    string_t s;
    string_init(&s, "I'm a pokemon");
    char c = at(&s, 1);
    cr_assert_eq(c, '\'');
    string_destroy(&s);
}

Test(at_string, at_string_mone)
{
    string_t s;
    string_init(&s, "0123");
    char c = at(&s, 4);
    cr_assert_eq(c, -1);
    string_destroy(&s);
}

Test(at_string, at_string_m1)
{
    string_t *s = NULL;
    char c = at(s, 4);
    cr_assert_eq(c, -1);
    string_destroy(s);
}
