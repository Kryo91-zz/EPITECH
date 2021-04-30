/*
** EPITECH PROJECT, 2019
** asm
** File description:
** check_types_test.c
*/

#include "asm.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(detect_types, should_detect_ind)
{
    args_type_t type = detect_types("42");

    cr_assert_eq(type, T_IND);
    type = detect_types(":label");
    cr_assert_eq(type, T_IND);
}

Test(detect_types, should_detect_dir)
{
    args_type_t type = detect_types("%42");

    cr_assert_eq(type, T_DIR);
}

Test(detect_types, should_detect_reg)
{
    args_type_t type = detect_types("r1");

    cr_assert_eq(type, T_REG);
}

Test(detect_types, should_detect_unknown)
{
    args_type_t type = detect_types("azerty");

    cr_assert_eq(type, T_UNKOWN);
}