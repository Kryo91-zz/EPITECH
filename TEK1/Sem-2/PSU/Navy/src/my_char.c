/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** my_char.c
*/

#include "../inc/my.h"

void description(void)
{
    my_printf("USAGE\n      ./navy [first_player_pid] navy_positions\nDESCRI");
    my_printf("PTION\n      first_player_pid: only for the 2nd player.");
    my_printf(" pid of the first player.\n      navy_positions: file");
    my_printf(" representing the positions of the ships.\n");
}

int my_char_ischar(char c)
{
    if ((c > 64 && c < 73))
        return (0);
    else
        return (1);
}

int my_char_ispoint(char c)
{
    if (c == ':')
        return (0);
    else
        return (1);
}

int my_char_isnum(char c)
{
    if ((c > 48 && c < 58))
        return (0);
    else
        return (1);
}