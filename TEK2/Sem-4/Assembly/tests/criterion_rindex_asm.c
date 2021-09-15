/*
** EPITECH PROJECT, 2020
** B-ASM-400-MPL-4-1-asmminilibc-corentin.petrau
** File description:
** criterion_rindex_asm.c
*/


#include "../inc/include_criterion.h"

Test(unit, get_simple_ocurence, .init=init, .fini=fini)
{
    char *str = rindex("hello", 'e');
    char *src = my_rindex("hello", 'e');

    cr_assert_str_eq(str, src);
}

Test(unit, get_complex_ocurence, .init=init, .fini=fini)
{
    char *str = rindex("hello", 'l');
    char *src = my_rindex("hello", 'l');

    cr_assert_str_eq(str, src);
}

Test(unit, get_no_ocurence, .init=init, .fini=fini)
{
    char *str = rindex("hello", 'z');
    char *src = my_rindex("hello", 'z');

    cr_assert(str == src);
}

Test(unit, get_no_ocurence_empty_string_and_cara, .init=init, .fini=fini)
{
    char *str = rindex("", 0);
    char *src = my_rindex("", 0);

    cr_assert(str == src);
}

Test(unit, get_cara_no_printable, .init=init, .fini=fini)
{
    char *str = rindex("hello\n", '\n');
    char *src = my_rindex("hello\n", '\n');

    cr_assert(str == src);
}
