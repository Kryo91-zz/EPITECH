/*
** EPITECH PROJECT, 2020
** criterion_ex01.c
** File description:
** ex01
*/

#include "../string.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(c_str_string, c_str_stringt)
{
    string_t s;
    string_init(&s, "I'm a pokemon");
    char const *str = c_str(&s);
    cr_assert_str_eq(str, "I'm a pokemon");
    string_destroy(&s);
}

Test(c_str_string, c_str_string_m1)
{
    string_t *s = NULL;
    char const *str = c_str(s);
    cr_assert_eq(str, NULL);
    string_destroy(s);
}


Test(c_str_string, c_str_string_m2)
{
    string_t s;
    string_init(&s, NULL);
    char const *str = c_str(&s);
    cr_assert_eq(str, NULL);
    string_destroy(&s);
}