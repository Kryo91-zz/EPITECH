/*
** EPITECH PROJECT, 2020
** B-ASM-400-MPL-4-1-asmminilibc-corentin.petrau
** File description:
** criterion_memset_asm.c
*/

#include "../inc/include_criterion.h"


Test(utils, set_memory_two, .init=init, .fini=fini)
{
    str = strdup("Hello world!");
    char *src = strdup("Hello world!");
    memset(src, '$', 2);
    my_memset(str, '$', 2);
    cr_assert_str_eq(src, str);
}

Test(utils, set_memory_zero, .init=init, .fini=fini)
{
    str = strdup("Hello world!");
    char *src = strdup("Hello world!");
    memset(src, '$', 0);
    my_memset(str, '$', 0);
    cr_assert_str_eq(src, str);
}


Test(utils, set_memory_len_more_higher, .init=init, .fini=fini)
{
    str = strdup("Hello world!");
    char *src = strdup("Hello world!");
    memset(src, '$', 15);
    my_memset(str, '$', 15);
    cr_assert_str_eq(src, str);
}

Test(utils, set_memory_with_string_empty, .init=init, .fini=fini)
{
    char st[150];
    char src[150];
    memset(src, '$', 150);
    my_memset(st, '$', 150);
    cr_assert_str_eq(st, src);
}