/*
** EPITECH PROJECT, 2020
** B-ASM-400-MPL-4-1-asmminilibc-corentin.petrau
** File description:
** criterion_memcpy_asm.c
*/

#include "../inc/include_criterion.h"

Test(unit, cpy_simple_string, .init=init, .fini=fini)
{
    char *str = strdup("Hello World!");
    char *src = strdup("Hello World!");

    memcpy(str, "yo", 2);
    my_memcpy(src, "yo", 2);

    cr_assert_str_eq(str, src);
}

Test(unit, cpy_empty_string, .init=init, .fini=fini)
{
    char *str = strdup("Hello World!");
    char *src = strdup("Hello World!");

    memcpy(str, "yo", 0);
    my_memcpy(src, "yo", 0);

    cr_assert_str_eq(str, src);
}

Test(unit, cpy_full_string, .init=init, .fini=fini)
{
    char *str = strdup("Hello World!");
    char *src = strdup("Hello World!");

    memcpy(str, "Pomme Poire?", 13);
    my_memcpy(src, "Pomme Poire?", 13);

    cr_assert_str_eq(str, src);
}

Test(unit, cpy_no_string, .init=init, .fini=fini)
{
    char *str = strdup("Hello World!");
    char *src = strdup("Hello World!");

    memcpy(str, "", 13);
    my_memcpy(src, "", 13);

    cr_assert_str_eq(str, src);
}