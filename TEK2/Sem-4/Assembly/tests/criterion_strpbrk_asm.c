/*
** EPITECH PROJECT, 2020
** B-ASM-400-MPL-4-1-asmminilibc-corentin.petrau
** File description:
** criterion_memcpy_asm.c
*/

#include "../inc/include_criterion.h"

Test(unit, check_simple_occurence, .init=init, .fini=fini)
{
    cr_assert_str_eq(strpbrk("hello", "hello"), my_strpbrk("hello", "hello"));
}

Test(unit, check_complex_occurence, .init=init, .fini=fini)
{
    cr_assert_str_eq(strpbrk("hello", "karibou"), my_strpbrk("hello", "karibou"));
}

Test(unit, check_no_occurence, .init=init, .fini=fini)
{
    cr_assert(strpbrk("hello", "karibu") == my_strpbrk("hello", "karibu"));
}

Test(unit, check_empty_string, .init=init, .fini=fini)
{
    cr_assert(strpbrk("hello", "") == my_strpbrk("hello", ""));
}

Test(unit, check_two_empty_string, .init=init, .fini=fini)
{
    cr_assert(strpbrk("", "") == my_strpbrk("", ""));
}