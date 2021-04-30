/*
** EPITECH PROJECT, 2020
** check all error
** File description:
** lem_in
*/

#include "../include/main.h"

void read_file(main_t *my_struct)
{
    char *buff = malloc(sizeof(char) * 10000);
    int offset = 0;

    while (read(0, buff + offset, 1) > 0 && offset < 9999)
        offset += 1;
    buff[offset] = '\0';
    my_struct->input = buff;
}
