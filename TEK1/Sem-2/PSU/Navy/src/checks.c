/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** checks.c
*/

#include "../inc/my.h"

int check_input(char *pos)
{
    if (my_strlen(pos) != 2)
        return (0);
    if (pos[0] < 65 || pos[0] > 72)
        return (0);
    if (pos[1] < '1' || pos[1] > '8')
        return (0);
    return (1);
}

int error(int ac, char **av)
{
    if (ac != 2 && ac != 3)
        return (1);
    int a = my_getnbr(av[1]);
    if (a == 0) {
        if (my_strcmp(av[1], "-h") == 0)
            return (0);
    }
    return (0);
}

int tcheck_file_error(char *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; ++i)
        if (str[i] == '\n')
            count += 1;
    count += 1;
    if (count != 5 && count != 4)
        return (1);
    if (my_char_isnum(str[0]) == 1 || my_char_isnum(str[8])  == 1 || \
    my_char_isnum(str[16]) == 1 || my_char_isnum(str[24]) == 1)
        return (1);
    if (my_char_ispoint(str[1]) == 1 || my_char_ispoint(str[9])  == 1 || \
    my_char_ispoint(str[17]) == 1 || my_char_ispoint(str[25]) == 1 || \
    my_char_ispoint(str[4]) == 1 || my_char_ispoint(str[12]) == 1 \
    || my_char_ispoint(str[20]) == 1 || my_char_ispoint(str[28]) == 1)
        return (1);
    return (tcheck_file_error2(str));
}

int tcheck_file_error2(char *str)
{
    if (my_char_isnum(str[3]) == 1 || my_char_isnum(str[6])  == 1 || \
    my_char_isnum(str[11]) == 1 || my_char_isnum(str[14]) == 1 || \
    my_char_isnum(str[19]) == 1 || my_char_isnum(str[22]) == 1 \
    || my_char_isnum(str[27]) == 1 || my_char_isnum(str[30]) == 1)
        return (1);
    if (my_char_ischar(str[2]) == 1 || my_char_ischar(str[5])  == 1 || \
    my_char_ischar(str[10]) == 1 || my_char_ischar(str[13]) == 1 || \
    my_char_ischar(str[18]) == 1 || my_char_ischar(str[21]) == 1 \
    || my_char_ischar(str[26]) == 1 || my_char_ischar(str[29]) == 1)
        return (1);
    return (tcheck_file_error3(str));
}

void count_sig2(int kiwi)
{
    if (req->sig2 == 0) {
        req->sigx = req->sig1;
        req->sig1 = 0;
        req->sig2 += 1;
    } else {
        req->sigy = req->sig1;
        req->sig1 = 0;
        req->sig2 += 1;
    }
}