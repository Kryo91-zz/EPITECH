/*
** EPITECH PROJECT, 2020
** Corewar, asm
** File description:
** check_types.c
*/

#include "asm.h"

args_type_t detect_types(char *str)
{
    if (str[0] == '%')
        return (T_DIR);
    if (str[0] == 'r' && \
    my_getnbr(str + 1) <= REG_NUMBER && my_getnbr(str + 1) >= 1)
        return (T_REG);
    if (isnum(str) == true)
        return (T_IND);
    if (str[0] == ':')
        return (T_IND);
    return (0);
}