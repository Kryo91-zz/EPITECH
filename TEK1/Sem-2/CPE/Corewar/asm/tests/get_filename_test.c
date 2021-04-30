/*
** EPITECH PROJECT, 2019
** asm
** File description:
** get_filename_test.c
*/

#include "asm.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(get_filename, should_get_filename)
{
    char *name[] = {
        get_filename("tmp/test.s"),
        get_filename("test.s"),
        get_filename("tmp/test"),
        get_filename("test")
    };

    cr_assert_str_eq(name[0], "test", "Failed at i = %d", 0);
    cr_assert_str_eq(name[1], "test", "Failed at i = %d", 1);
    cr_assert_str_eq(name[2], "test", "Failed at i = %d", 2);
    cr_assert_str_eq(name[3], "test", "Failed at i = %d", 3);
}