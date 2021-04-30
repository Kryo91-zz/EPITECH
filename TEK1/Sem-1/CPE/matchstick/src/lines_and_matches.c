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

int matches(int j, char **play, char **av)
{
    char *buff = malloc(sizeof(char *) * 4096);
    size_t len = 0;

    my_printf("Matches: ");
    int i = getline(&buff, &len, stdin);
    int k = my_getnbr(buff);
    int chec = count_number_of_matches(play, j);

    if (i <= 0)
        return (0);
    while (k > my_getnbr(av[2]) || k < 1 || k > chec)
        return (error(k, av, play, j));
    ++turn;
    my_printf("Player removed %d match(es) from line %d\n", k, j);
    print_game_return_game(j, k, play, av);
}

int lines_match(char **play, char **av)
{
    int buf = 0;
    char *buff = malloc(sizeof(char) * 4096);
    size_t len = 0;

    if (tchek(play) == 1)
        return (1);
    else if (tchek(play) == 2) {
        my_printf("You lost, too bad...\n");
        return (2);
    }
    if (turn % 2 == 0)
        intellignece_artificial(play, buf, av);
    else {
        my_printf("\nYour turn:\nLine: ");
        int i = getline(&buff, &len, stdin);
        int j = my_getnbr(buff);
        if (i <= 0) {
            return (0);
        }
        replay(j, play, av, buff);
    }
}

void intellignece_artificial(char **play, int ia, char **av)
{
    ++turn;
    int line = chooseline(play);
    int matches = count_number_of_matches(play, line);
    int limits = my_getnbr(av[2]);

    if (matches > 1)
        matches -= 1;
    if (matches > limits)
        matches = limits;
    my_printf("\nAI's turn...\n");
    my_printf("AI removed %d match(es) from line %d\n", matches, line);
    print_game_return_game(line, matches, play, av);
}

int lose_condition(int count)
{
    if (count == 0) {
        if (turn % 2 == 1) {
            my_printf("I lost... snif... but I'll get you next time!!\n");
            return (1);
        } else {
            return (2);
        }
    }
    return (0);
}