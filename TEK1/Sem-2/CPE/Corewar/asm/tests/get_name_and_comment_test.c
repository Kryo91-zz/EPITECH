/*
** EPITECH PROJECT, 2019
** asm
** File description:
** get_name_and_comment_test.c
*/

#include "asm.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(offset_str, should_cut)
{
    char *str = offset_str("str_test", 4);

    cr_assert_str_eq(str, "test");
    free(str);
}

Test(offset_str, should_abort)
{
    cr_assert_null(offset_str(NULL, 0));
    cr_assert_null(offset_str("HELLO", 8));
}