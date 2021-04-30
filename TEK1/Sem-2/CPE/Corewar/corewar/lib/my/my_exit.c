/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** my_exit.c
*/

#include <stdlib.h>
#include <unistd.h>

int my_strlen(char const *str);

void my_exit(char *str, int code)
{
    if (!str)
        exit(code);
    write(2, str, my_strlen(str));
    exit(code);
}