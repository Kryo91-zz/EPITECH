/*
** EPITECH PROJECT, 2020
** Corewar, asm
** File description:
** check_types.c
*/

#include "asm.h"

bool check_params(char *str)
{
    if (str[0] == '%')
        return (true);
    if (str[0] == 'r' && \
    my_getnbr(str + 1) <= REG_NUMBER && my_getnbr(str + 1) >= 1)
        return (true);
    if (isnum(str) == true)
        return (true);
    if (str[0] == ':')
        return (true);
    return (false);
}