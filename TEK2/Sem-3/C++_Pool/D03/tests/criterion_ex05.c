/*
** EPITECH PROJECT, 2020
** criterion_ex01.c
** File description:
** ex01
*/

#include "../string.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(size_string, size_stringt)
{
    string_t s;
    string_init(&s, "I'm a pokemon");
    int i = size(&s);
    cr_assert_eq(i, 13);
    string_destroy(&s);
}

Test(size_string, size_string_mone)
{
    string_t s;
    string_init(&s, NULL);
    int i = size(&s);
    cr_assert_eq(i, -1);
    string_destroy(&s);
}

Test(size_string, size_string_m1)
{
    string_t *s = NULL;
    int i = size(s);
    cr_assert_eq(i, -1);
    string_destroy(s);
}
