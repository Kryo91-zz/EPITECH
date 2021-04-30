/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** echo.c
*/

#include "../inc/my.h"

int idx_find(char *buff)
{
    for (int i = 1; buff[i] != '\0'; i++)
        if (buff[i] == 34)
            return (i);
}

char *get_msg(char *buff)
{
    int idx = idx_find(buff);
    int size = my_strlen(buff);
    int i = 0;
    char *cmd = malloc(sizeof(char) * (size + 1));

    for (; buff[idx] != '\0';i++, idx++)
        cmd[i] = buff[idx];
    cmd[i] = 0;
    return (cmd);
}