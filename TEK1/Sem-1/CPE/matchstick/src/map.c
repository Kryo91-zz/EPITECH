/*
** EPITECH PROJECT, 2019
** CPE_matchstick_bootstrap_2019
** File description:
** map.c
*/

#include <stdlib.h>
#include "my.h"

void matchs(char **map, int len)
{
    int empty = len / 2 - 1;
    int keep = 1;
    int y;

    for (int i = 1; map[i + 1]; i += 1) {
        for (y = 1; y <= empty; y += 1);
        for (int j = 0; j < keep; j += 1) {
            map[i][y] = '|';
            y += 1;
        }
        empty -= 1;
        keep += 2;
    }
}

char **map(int len, int lines)
{
    char **map = malloc(sizeof(char *) * 4096);

    map[lines + 1] = "\0";
    for (int i = 0; i < lines; i += 1) {
        map[i] = malloc(sizeof(char) * 4096);
        map[i][len + 1] = '\0';
        for (int y = 0; y < len; y += 1) {
            if (y == 0 || i == 0 || i == lines - 1 || y == len - 1)
                map[i][y] = '*';
            else
                map[i][y] = ' ';
        }
    }
    matchs(map, len);
    return (map);
}

int error(int k, char **av, char **play, int j)
{
    int check = count_number_of_matches(play, j);

    if (k > my_getnbr(av[2])) {
        my_printf("Error: you cannot remove more than %s \
matches per turn\n", av[2]);
            return (find_the_line(play, av));
    }
    if (k > check) {
        my_printf("Error: not enough matches on this line\n");
        return (find_the_line(play, av));
    }
    if (k < 1) {
        my_printf("Error: you have to remove at least one match\n");
        return (find_the_line(play, av));
    }
}

int find_the_line(char **play, char **av)
{
    size_t len = 0;
    char *buff = malloc(sizeof(char *) * 4096);

    my_printf("Line: ");
    int i = getline(&buff, &len, stdin);
    int j = my_getnbr(buff);
    if (i <= 0)
        return (0);
    replay(j, play, av, buff);
}