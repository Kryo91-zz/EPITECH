/*
** EPITECH PROJECT, 2020
** criterion_ex01.c
** File description:
** ex01
*/

#include "../string.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(append_string, assignc_string_null_)
{
    string_t s;
    string_init(&s, "I'm a pokemon");
    append_c(&s, NULL);
    cr_assert_str_eq(s.str, "I'm a pokemon");
    string_destroy(&s);
}

Test(append_string, assignc_string_null2_)
{
    string_t *s = NULL;
    append_c(s, NULL);
    cr_assert_eq(s, NULL);
    string_destroy(s);
}

Test(append_string, assignc_string_null_and_const_not)
{
    string_t s;
    string_init(&s, NULL);
    append_c(&s, "Not");
    cr_assert_str_eq(s.str, "Not");
    string_destroy(&s);
}