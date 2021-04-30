/*
** EPITECH PROJECT, 2019
** CPE_matchstick_bootstrap_2019
** File description:
** main.c
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

int tchek(char **play)
{
    int i = 0;
    int j = 0;
    int count = 0;

    while (play[j] != NULL) {
        while (play[j][i] != '\0') {
            if (play[j][i] == '|') {
                count = 1;
                ++i;
            }
            ++i;
        }
        ++j;
        i = 0;
    }
    return (lose_condition(count));
}

int print_game_return_game(int i, int j, char **play, char **av)
{
    int nb = 0;
    int line = i;
    int stick = j;

    if (tchek_2(play, lose) == 1) {
        my_printf("IA lose\n");
        return (1);
    } else if (tchek_2(play, lose) == 2) {
        my_printf("You lost, too bad...\n");
        return (2);
    }
    print_board_game(line, stick, play, av);
    while (play[nb] != NULL) {
        my_printf("%s\n", play[nb]);
        ++nb;
    }
    ++lose;
    return (lines_match(play, av));
}

int lose_condition_2(int count, int lose)
{
    if (count == 0) {
        if (lose % 2 == 0) {
            return (1);
        } else if (lose % 2 == 1) {
            return (2);
        }
    }
    return (0);
}

int tchek_2(char **play, int lose)
{
    int i = 0;
    int j = 0;
    int count = 0;

    while (play[j] != NULL) {
        while (play[j][i] != '\0') {
            if (play[j][i] == '|') {
                count = 1;
                ++i;
            }
            ++i;
        }
        ++j;
        i = 0;
    }
    return (lose_condition_2(count, lose));
}