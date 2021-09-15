/*
** EPITECH PROJECT, 2020
** B-ASM-400-MPL-4-1-asmminilibc-corentin.petrau
** File description:
** criterion_strlen_asm.c
*/

#include "../inc/include_criterion.h"


Test(utils, simple_string, .init=init, .fini=fini)
{
    str = strdup("test criterion");
    cr_assert_eq(strlen(str), (*my_strlen)(str));
}

Test(utils, strlen_empty_string, .init=init, .fini=fini)
{
    str = strdup("");
    cr_assert_eq(strlen(str), (*my_strlen)(str));
}

Test(utils, strlen_string_size_one, .init=init, .fini=fini)
{
    str = strdup("a");
    cr_assert_eq(strlen(str), (*my_strlen)(str));
}