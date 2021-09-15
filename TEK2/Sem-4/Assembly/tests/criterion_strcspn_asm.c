/*
** EPITECH PROJECT, 2020
** B-ASM-400-MPL-4-1-asmminilibc-corentin.petrau
** File description:
** criterion_memcpy_asm.c
*/

#include "../inc/include_criterion.h"

Test(unit, get_number_of_no_occurence, .init=init, .fini=fini)
{
    cr_assert_eq(strcspn("hallo", "1234a"), my_strcspn("hallo", "1234a"));
}

Test(unit, get_number_of_no_occurence_complete, .init=init, .fini=fini)
{
    cr_assert_eq(strcspn("hallo", "1234"), my_strcspn("hallo", "1234"));
}

Test(unit, get_number_of_no_occurence_zero, .init=init, .fini=fini)
{
    cr_assert_eq(strcspn("hallo", "h1234a"), my_strcspn("hallo", "h1234a"));
}

Test(unit, get_number_of_no_occurence_empty_string, .init=init, .fini=fini)
{
    cr_assert_eq(strcspn("hallo", ""), my_strcspn("hallo", ""));
}

Test(unit, get_number_of_no_occurence_two_empty_string, .init=init, .fini=fini)
{
    cr_assert_eq(strcspn("", ""), my_strcspn("", ""));
}

Test(unit, get_number_of_no_occurence_without_text_, .init=init, .fini=fini)
{
    cr_assert_eq(strcspn("", "hello"), my_strcspn("", "hello"));
}