/*
** EPITECH PROJECT, 2020
** criterion_ex01.c
** File description:
** ex01
*/

#include "../string.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(clear_string, clear_stringt)
{
    string_t s;
    string_init(&s, "I'm a pokemon");
    clear(&s);
    cr_assert_str_eq(s.str, "");
    string_destroy(&s);
}

Test(clear_string, clear_string_m1)
{
    string_t *s = NULL;
    clear(s);
    cr_assert_eq(s, NULL);
    string_destroy(s);
}
