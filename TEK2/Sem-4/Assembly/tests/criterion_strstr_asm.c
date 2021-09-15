/*
** EPITECH PROJECT, 2020
** B-ASM-400-MPL-4-1-asmminilibc-corentin.petrau
** File description:
** criterion_memcpy_asm.c
*/

#include "../inc/include_criterion.h"

Test(unit, sub_simple_occurence, .init=init, .fini=fini)
{
    char *str = strstr("hello", "e");
    char *src = my_strstr("hello", "e");

    cr_assert_str_eq(str, src);
}

Test(unit, sub_complex_ocurence, .init=init, .fini=fini)
{
    char *str = strstr("Azerty or qwerty my friend ? :)", " ");
    char *src = my_strstr("Azerty or qwerty my friend ? :)", " ");

    cr_assert_str_eq(str, src);
}

Test(unit, sub_no_ocurence, .init=init, .fini=fini)
{
    char *str = strstr("hello", "");
    char *src = my_strstr("hello", "");

    cr_assert(str == src);
}

Test(unit, sub_no_ocurence_empty_string_and_cara, .init=init, .fini=fini)
{
    char *str = strstr("", "z");
    char *src = my_strstr("", "z");

    cr_assert(str == src);
}

Test(unit, sub_cara_no_printable, .init=init, .fini=fini)
{
    char *str = strstr("hello\nWorld!", "llo\n");
    char *src = my_strstr("hello\nWorld!", "llo\n");

    cr_assert(str == src);
}