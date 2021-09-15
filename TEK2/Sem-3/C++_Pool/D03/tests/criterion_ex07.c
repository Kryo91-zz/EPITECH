/*
** EPITECH PROJECT, 2020
** criterion_ex01.c
** File description:
** ex01
*/

#include "../string.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(copy_string, copy_stringt)
{
    string_t s;
    string_init(&s, "I'm a pokemon");
    size_t i = copy(&s, "epitech", 4, 21);
    cr_assert_eq(i, 0);
    string_destroy(&s);
}

Test(copy_string, copy_string_error2)
{
    string_t s;
    string_init(&s, "I'm a pokemon");
    size_t i = copy(&s, "epitech", 0, 2);
    cr_assert_eq(i, 0);
    string_destroy(&s);
}

Test(copy_string, copy_string_error3)
{
    string_t *s = NULL;
    size_t i = copy(s, "epitech", 4, 2);
    cr_assert_eq(i, 0);
    string_destroy(s);
}
