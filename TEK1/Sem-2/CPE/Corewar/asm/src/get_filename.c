/*
** EPITECH PROJECT, 2019
** asm
** File description:
** get_filename.c
*/

#include "asm.h"

void copy_up_to_n(char *dest, char const *src, int n)
{
    int idx = 0;

    for (int i = 0; src[i]; i++) {
        if (i <= n) {
            dest[idx] = src[i];
            idx++;
        }
    }
}

char *get_filename(char const *str)
{
    int i = 0;
    char *dest = NULL;
    char *dp = my_strdup(str);

    my_revstr(dp);
    for (; dp[i] && dp[i] != '/'; i += 1);
    dest = malloc(sizeof(char) * (i + 1));
    dest[i] = 0;
    copy_up_to_n(dest, dp, i - 1);
    my_revstr(dest);
    for (i = 0; dest[i] != '.'; i += 1);
    dp = malloc(sizeof(char) * (i + 1));
    dp[i] = 0;
    copy_up_to_n(dp, dest, i - 1);
    return (dp);
}