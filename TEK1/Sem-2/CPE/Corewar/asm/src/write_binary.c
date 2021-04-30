/*
** EPITECH PROJECT, 2019
** asm
** File description:
** write_in_file.c
*/

#include "asm.h"

void write_big_endian(int fd, void *bytes, int size)
{
    char *tmp = bytes;

    for (int i = size - 1; i >= 0; i--)
        write(fd, &(tmp[i]), 1);
}

void write_reg(int fd, char const *param)
{
    unsigned char reg = my_getnbr(param + 1);

    write_big_endian(fd, &reg, sizeof(reg));
}

void write_ind(int fd, char const *param)
{
    int ind = my_getnbr(param);

    write_big_endian(fd, &ind, IND_SIZE);
}

void write_dir(int fd, char const *param, int size)
{
    short dir_short = my_getnbr(param + 1);
    int dir_int = my_getnbr(param + 1);

    if (size == 2)
        write_big_endian(fd, &dir_short, 2);
    else
        write_big_endian(fd, &dir_int, 4);
}