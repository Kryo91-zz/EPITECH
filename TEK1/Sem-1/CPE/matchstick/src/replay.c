/*
** EPITECH PROJECT, 2019
** CPE_matchstick_bootstrap_2019
** File description:
** main.c
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"

int replay(int j, char **play, char **av, char *buff)
{
    size_t len = 0;

    while (j > my_getnbr(av[1]) || j < 1) {
        if (j > my_getnbr(av[1]) || my_strlen(buff) == 1) {
            my_printf("Error: this line is out of range\n");
            my_printf("Line: ");
            int i = getline(&buff, &len, stdin);
            j = my_getnbr(buff);
            if (i <= 0)
                return (0);
        } else if (my_str_isnum(buff) == 1) {
            my_printf("Error: invalid input (positive number expected)\n");
            my_printf("Line: ");
            int i = getline(&buff, &len, stdin);
            j = my_getnbr(buff);
            if (i <= 0)
                return (0);
        }
    }
    matches(j, play, av);
}

int chooseline(char **map)
{
    int count = 0;
    int where = 0;
    int count2 = 0;

    for (int i = 0; map[i] != NULL; i += 1) {
        for (int y = 0; map[i][y] != '\0'; y += 1){
            if (map[i][y] == '|')
                count += 1;
        }
        if (count > count2) {
            count2 = count;
            where = i;
        }
        count = 0;
    }
    return (where);
}

int count_number_of_matches(char **map, int line)
{
    int count  = 0;

    for (int i = 0; map[line][i] != '\0'; i += 1)
        if (map[line][i] == '|')
            count += 1;
    return (count);
}