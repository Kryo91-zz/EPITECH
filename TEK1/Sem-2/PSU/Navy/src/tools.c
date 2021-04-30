/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** tools.c
*/

#include "../inc/my.h"

int count_boats(char **map)
{
    int count = 0;
    int ind = 0;
    char boat = '1';

    while (ind < 6) {
        boat = ind + 48;
        for (int i = 1; i < 10; i += 1)
            for (int y = 1; y < 17; y += 1)
                if (map[i][y] == boat)
                    count += 1;
        ind += 1;
    }
    return (count);
}

int count_crosses(char **map)
{
    int count = 0;
    char boat = 'x';

    for (int i = 1; i < 10; i += 1)
        for (int y = 1; y < 17; y += 1)
            if (map[i][y] == boat)
                count += 1;
return (count);
}

char *unbackn(char *str)
{
    int i = 0;
    char *buf = malloc(sizeof(char) * 4096);

    while (str[i] != '\n') {
        buf[i] = str[i];
        i += 1;
    }
    buf[i] = '\0';
    return (buf);
}

int letters_to_int(char pos)
{
    int intp = 0;

    if (pos >= 65)
        intp = (pos - 65) * 2 + 3;
    else
        intp = pos - 48 + 2;
    return (intp);
}

char *int_to_letters(int x, int y)
{
    char *str = malloc(sizeof(char) * 3);

    if (x % 2 == 0)
        str[0] = (x / 2 - 3) + 65;
    else
        str[0] = (x / 2 - 1) + 65;
    str[1] = (y - 2) + 48;
    return (str);
}