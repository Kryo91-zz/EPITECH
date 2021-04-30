/*
** EPITECH PROJECT, 2019
** asm
** File description:
** check_params_test.c
*/

#include "asm.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(check_params, should_return_true)
{
    bool ret[] = {
        check_params("r1"),
        check_params("%12"),
        check_params("42"),
        check_params(":label")
    };

    for (int i = 0; i < 4; i++) {
        cr_assert(ret[i], "Failed at i = %d\n", i);
    }
}

Test(check_params, should_return_false)
{
    bool ret[] = {
        check_params("r20"),
        check_params("%azerty"),
        check_params("error")
    };

    for (int i = 0; i < 3; i++) {
        cr_assert(!ret[i], "Failed at i = %d\n", i);
    }
}