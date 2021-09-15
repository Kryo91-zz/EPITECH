/*
** EPITECH PROJECT, 2020
** B-ASM-400-MPL-4-1-asmminilibc-corentin.petrau
** File description:
** criterion_strlen_asm.c
*/

#include "../inc/include_criterion.h"


Test(utils, find_occurence_simple, .init=init, .fini=fini)
{
    str = strdup("Hello world");
    char *res_func = strchr(str, 'w');
    char *res_mine = (*my_strchr)(str, 'w');
    cr_assert_str_eq(res_func, res_mine);
}

Test(utils, find_occurence_advanced, .init=init, .fini=fini)
{
    str = strdup("Hello world");
    char *res_func = strchr(str, 'l');
    char *res_mine = (*my_strchr)(str, 'l');
    cr_assert_str_eq(res_func, res_mine);
}

Test(utils, strlen_string_empty, .init=init, .fini=fini)
{
    str = strdup("");
    char *res_mine = (*my_strchr)(str, 'l');
    cr_assert(res_mine == NULL);
}

Test(utils, strlen_string_no_occurence, .init=init, .fini=fini)
{
    str = strdup("Hello World!");
    char *res_mine = (*my_strchr)(str, 'z');
    cr_assert(res_mine == NULL);
}

Test(utils, strlen_string_2_empty, .init=init, .fini=fini)
{
    str = strdup("Hello World!");
    char *res_func = strchr(str, 0);
    char *res_mine = (*my_strchr)(str, 0);
    cr_assert(res_func == res_mine);
}

Test(utils, strlen_one_chara, .init=init, .fini=fini)
{
    str = strdup("H");
    char *res_func = strchr(str, 'h');
    char *res_mine = (*my_strchr)(str, 'h');
    cr_assert(res_func == res_mine);
}