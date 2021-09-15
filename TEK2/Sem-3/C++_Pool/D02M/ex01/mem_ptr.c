/*
** EPITECH PROJECT, 2020
** mem_ptr
** File description:
** amem_ptr.c.c
*/

#include "mem_ptr.h"
#include <string.h>
#include <stdlib.h>
#include <stddef.h>

void add_str(const char *str1, const char *str2, char **res)
{
    int i = strlen(str1);
    int j = strlen(str2);

    if (i || j) {
        *res = malloc(i + j + 1);
        strcpy(*res, str1);
        strcat(*res, str2);
    } else {
        *res = NULL;
    }

}

void add_str_struct(str_op_t *str_op)
{
    add_str(str_op->str1, str_op->str2, &str_op->res);
}