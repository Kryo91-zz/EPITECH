/*
** EPITECH PROJECT, 2020
** criterion_ex01.c
** File description:
** ex01
*/

#include "../string.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(append_string, append_stringt_to_stringt)
{
    string_t s;
    string_t str;
    string_init(&s, "I'm a pokemon");
    string_init(&str, "Lul");
    append_s(&s, &str);
    cr_assert_str_eq(s.str, "I'm a pokemonLul");
    string_destroy(&s);
}

Test(append_string, append_stringt_to_stringt_null)
{
    string_t s;
    string_t str;
    string_init(&s, "I'm a pokemon");
    string_init(&str, NULL);
    append_s(&s, &str);
    cr_assert_str_eq(s.str, "I'm a pokemon");
    string_destroy(&s);
}

Test(append_string, append_Null)
{
    string_t *s = NULL;
    string_t *str = NULL;
    append_s(s, str);
    cr_assert_eq(s, NULL);
    string_destroy(s);
}

Test(append_string, assignc_string)
{
    string_t s;
    string_t str;
    string_init(&s, NULL);
    string_init(&str, "lul");
    append_s(&s, &str);
    cr_assert_str_eq(s.str, "lul");
    string_destroy(&s);
}

Test(append_string, assignc_string_null)
{
    string_t s;
    string_init(&s, "I'm a pokemon");
    append_c(&s, "123");
    cr_assert_str_eq(s.str, "I'm a pokemon123");
    string_destroy(&s);
}