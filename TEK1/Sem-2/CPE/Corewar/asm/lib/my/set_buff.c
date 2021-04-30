/*
** EPITECH PROJECT, 2019
** asm
** File description:
** set_buff.c
*/

#include <stdlib.h>

void set_buff(void *buff, int fill, size_t nb_bytes)
{
    char *setter = buff;

    for (int i = 0; i < nb_bytes; i++)
        setter[i] = fill;
}