/*
** EPITECH PROJECT, 2019
** CPE_matchstick_bootstrap_2019
** File description:
** game.c
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

void print_board_game(int line, int nb_matches, char **map, char **av)
{
    int i = my_getnbr(av[1]);
    i = i + (i-1);

    while (map[line][i] != '\0' && nb_matches > 0) {
        if (map[line][i] == '|') {
            map[line][i] = ' ';
            nb_matches -= 1;
        }
        i -= 1;
    }
}

void print_board_game_one(int line, int nb_matches, char **map)
{
    int i = 7;

    while (map[line][i] != 0 && nb_matches > 0) {
        if (map[line][i] == '|') {
            map[line][i] = ' ';
            nb_matches -= 1;
        }
        i -= 1;
    }
}

int scan_matches_ia(char **play)
{
    int i = 0;
    int j = 0;
    int count = 0;

    while (play[j] != NULL) {
        while (play[j][i] != '\0') {
            if (play[j][i] == '|') {
                count = j;
                ++i;
                return (count);
            }
            ++i;
        }
        ++j;
        i = 0;
    }
    return (count);
}

int scan_matches(char **play)
{
    int i = 0;
    int j = 0;
    int count = 0;

    while (play[j] != NULL) {
        while (play[j][i] != '\0') {
            if (play[j][i] == '|') {
                count = j;
                ++i;
                return (count);
            }
            ++i;
        }
        ++j;
        i = 0;
    }
    return (count);
}