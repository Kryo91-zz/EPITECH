/*
** EPITECH PROJECT, 2020
** criterion_ex01.c
** File description:
** ex01
*/

#include "../string.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(compare_c_string, compare_c_stringt)
{
    string_t s;
    string_init(&s, "I'm a pokemon");
    int i = compare_c(&s, "I'm a pokemon");
    cr_assert_eq(i, 0);
    string_destroy(&s);
}

Test(compare_c_string, compare_c_string_mone)
{
    string_t s;
    string_init(&s, "0123564");
    int i = compare_c(&s, "01234");
    cr_assert_eq(i, 1);
    string_destroy(&s);
}

Test(compare_c_string, compare_c_string_m1)
{
    string_t s;
    string_init(&s, "");
    int i = compare_c(&s, "pomme");
    cr_assert_eq(i, -112);
    string_destroy(&s);
}

Test(compare_s_string, compare_s_stringt)
{
    string_t s;
    string_init(&s, "I'm a pokemon");
    string_t str;
    string_init(&str, "I'm a pokemon");
    int i = compare_s(&s, &str);
    cr_assert_eq(i, 0);
    string_destroy(&s);
}

Test(compare_s_string, compare_s_string_mone)
{
    string_t s;
    string_init(&s, "0123564");
    string_t str;
    string_init(&str, "01234");
    int i = compare_s(&s, &str);
    cr_assert_eq(i, 1);
    string_destroy(&s);
}
