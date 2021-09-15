/*
** EPITECH PROJECT, 2020
** B-ASM-400-MPL-4-1-asmminilibc-corentin.petrau
** File description:
** criterion_memset_asm.c
*/

#include "../inc/include_criterion.h"

Test(unit, compare_simple_string, .init=init, .fini=fini)
{
    char *str = "pomme";
    char *src = "pomme";

    cr_assert_eq(strcmp(str, src), my_strcmp(str, src));
}

Test(unit, compare_complexe_string, .init=init, .fini=fini)
{
    char *str = "je suis une pomme qui parle\net qui mange une autre pomme\n";
    char *src = "je suis une pomme qui parle\net qui mange une autre pomme\n";

    cr_assert_eq(strcmp(str, src), my_strcmp(str, src));
}

Test(unit, compare_empty_string, .init=init, .fini=fini)
{
    char *str = "";
    char *src = "";

    cr_assert_eq(strcmp(str, src), my_strcmp(str, src));
}

Test(unit, compare_one_chara, .init=init, .fini=fini)
{
    char *str = "a";
    char *src = "a";

    cr_assert_eq(strcmp(str, src), my_strcmp(str, src));
}