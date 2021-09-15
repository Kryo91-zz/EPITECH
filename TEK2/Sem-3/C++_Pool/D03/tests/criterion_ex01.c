/*
** EPITECH PROJECT, 2020
** criterion_ex01.c
** File description:
** ex01
*/

#include "../string.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(assign_string, assign_stringt_to_stringt)
{
    string_t s;
    string_t str;
    string_init(&s, "I'm a pokemon");
    string_init(&str, "Lul");
    assign_s(&s, &str);
    cr_assert_str_eq(s.str, "Lul");
    string_destroy(&s);
}

Test(assign_string, assign_stringt_to_stringt_null)
{
    string_t s;
    string_t str;
    string_init(&s, "I'm a pokemon");
    string_init(&str, NULL);
    assign_s(&s, &str);
    cr_assert_eq(s.str, NULL);
    string_destroy(&s);
}

Test(assign_string, assign_Null)
{
    string_t *s = NULL;
    string_t *str = NULL;
    assign_s(s, str);
    cr_assert_eq(s, NULL);
    string_destroy(s);
}

Test(assign_string, assignc_string)
{
    string_t s;
    string_init(&s, "I'm a pokemon");
    assign_c(&s, "lul");
    cr_assert_str_eq(s.str, "lul");
    string_destroy(&s);
}

Test(assign_string, assignc_string_null)
{
    string_t s;
    string_init(&s, "I'm a pokemon");
    assign_c(&s, NULL);
    cr_assert_eq(s.str, NULL);
    string_destroy(&s);
}