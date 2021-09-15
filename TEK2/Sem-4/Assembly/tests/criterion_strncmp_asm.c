/*
** EPITECH PROJECT, 2020
** B-ASM-400-MPL-4-1-asmminilibc-corentin.petrau
** File description:
** criterion_memcpy_asm.c
*/

#include "../inc/include_criterion.h"

Test(unit, compare_2_chara_of_string, .init=init, .fini=fini)
{
    cr_assert(strncmp("hello", "hey", 2) == my_strncmp("hello", "hey", 2));
}

Test(unit, compare_all_chara_of_string, .init=init, .fini=fini)
{
    cr_assert(strncmp("hello", "hello", 5) == my_strncmp("hello", "hello", 5));
}

Test(unit, compare_all_plus_chara_of_string, .init=init, .fini=fini)
{
    cr_assert(strncmp("hello", "hello", 10) == my_strncmp("hello", "hello", 10));
}

Test(unit, compare_zero_chara_of_string, .init=init, .fini=fini)
{
    cr_assert(strncmp("hello", "hello", 0) == my_strncmp("hello", "hello", 0));
}