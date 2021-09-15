/*
** EPITECH PROJECT, 2020
** criterion_ex00.c
** File description:
** Ex00
*/

#include "../string.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(init_a_string, init_string)
{
    string_t s;
    string_init(&s, "Hello world");
    cr_assert_str_eq(s.str, "Hello world");
    string_destroy(&s);
}

Test(init_a_string_null, init_string_null)
{
    string_t s;
    string_init(&s, NULL);
    cr_assert_eq(s.str, NULL);
}

Test(init_a_null, init_null)
{
    string_t *s = NULL;
    string_init(s, NULL);
    cr_assert_eq(s, NULL);
}