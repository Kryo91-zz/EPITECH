/*
** EPITECH PROJECT, 2019
** asm
** File description:
** check_labels_test.c
*/

#include "asm.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(str_contains, should_return_true_and_false)
{
    cr_assert(str_contains("Hello World!", 'H'));
    cr_assert(!str_contains("Hello World!", 'A'));
}

Test(is_right_chars, should_return_true)
{
    cr_assert(is_right_chars("lol", "lo"));
}

Test(is_right_chars, should_return_false)
{
    cr_assert(!is_right_chars("lol", "42"));
}

Test(contains_spaces, should_return_true)
{
    cr_assert(contains_spaces("big oof"), "big oof\n");
    cr_assert(contains_spaces("big\toof"), "big\\toof\n");
    cr_assert(contains_spaces("big\noof"), "big\\noof\n");
}