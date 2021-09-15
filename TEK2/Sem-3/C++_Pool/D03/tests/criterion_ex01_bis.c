/*
** EPITECH PROJECT, 2020
** criterion_ex01.c
** File description:
** ex01
*/

#include "../string.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(assign_string, assignc_null)
{
    string_t *s = NULL;
    assign_c(s, "Lul");
    cr_assert_eq(s, NULL);
    string_destroy(s);
}
