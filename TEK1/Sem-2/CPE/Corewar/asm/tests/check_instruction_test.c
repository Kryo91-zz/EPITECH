/*
** EPITECH PROJECT, 2019
** asm
** File description:
** check_instruction_test.c
*/

#include "asm.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(is_correct, should_return_true)
{
    char *tmp[] = {
        "attack:	ld	%65, r8",
        "	st	r8, 100",
        "	ld	15, r4",
        "label:   ",
    };
    bool ret[] = {
        is_correct(tmp[0]),
        is_correct(tmp[1]),
        is_correct(tmp[2]),
        is_correct(tmp[3])
    };

    for (int i = 0; i < 4; i++) {
        cr_assert(ret[i], "Failed at %d assertion\n", i);
    }
}

Test(is_correct, should_return_false)
{
    char *tmp[] = {
        "attack:	ld	%65, r8, mdr, 123",
        "	st	r8, 100a",
        "	ld	15 r4",
        "label: lol",
        ":lol: st r8, 100"
    };
    bool ret[] = {
        is_correct(tmp[0]),
        is_correct(tmp[1]),
        is_correct(tmp[2]),
        is_correct(tmp[3]),
        is_correct(tmp[4])
    };

    for (int i = 0; i < 5; i++) {
        cr_assert(!ret[i], "Failed at %d assertion\n", i);
    }
}