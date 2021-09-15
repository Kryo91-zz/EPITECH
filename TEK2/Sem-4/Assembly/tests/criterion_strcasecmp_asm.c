/*
** EPITECH PROJECT, 2020
** B-ASM-400-MPL-4-1-asmminilibc-corentin.petrau
** File description:
** criterion_memcpy_asm.c
*/

#include "../inc/include_criterion.h"

Test(unit, compare_simple_string_without_caps, .init=init, .fini=fini)
{
    char *str = "hello";
    char *src = "hello";

    cr_assert_eq(strcasecmp(str, src), my_strcasecmp(str, src));
}

Test(unit, compare_simple_string_with_caps, .init=init, .fini=fini)
{
    char *str = "HelLo";
    char *src = "heLlo";

    cr_assert_eq(strcasecmp(str, src), my_strcasecmp(str, src));
}

Test(unit, compare_simple_string_different_lenght, .init=init, .fini=fini)
{
    char *str = "He";
    char *src = "heL";

    cr_assert_eq(strcasecmp(str, src), my_strcasecmp(str, src));
}

Test(unit, compare_simple_string_with_no_letter, .init=init, .fini=fini)
{
    char *str = "(-563145_|#";
    char *src = "(-563145_|#";

    cr_assert_eq(strcasecmp(str, src), my_strcasecmp(str, src));
}