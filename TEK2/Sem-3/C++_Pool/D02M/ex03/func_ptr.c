/*
** EPITECH PROJECT, 2020
** func_ptr
** File description:
** func_ptr.c
*/

#include "func_ptr.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "func_ptr_enum.h"

void print_normal(const char *str)
{
    printf("%s\n", str);
}

void print_reverse(const char *str)
{
    int i = strlen(str) - 1;

    for (; i >= 0; --i)
        printf("%c", str[i]);
    printf("\n");
}

void print_upper(const char *str)
{
    char *src = malloc(sizeof(char) * strlen(str) + 1);

    for (int i = 0; str[i]; ++i) {
        if (str[i] >= 97 && str[i] <= 122)
            src[i] = str[i] - 32;
        else
            src[i] = str[i];
        printf("%c", src[i]);
    }
    printf("\n");
}

void print_42(const char *str)
{
    str = NULL;

    printf("42\n");
}

void do_action(action_t action, const char *str)
{
    for (int i = 0; i < 4; ++i) {
        if (tab[i].str == action)
            tab[i].p(str);
    }
}