/*
** EPITECH PROJECT, 2019
** CPE_date_2019
** File description:
** main.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include "my.h"

void error_handing(char *str)
{
    int count = my_strlen(str);
    int lar = 0;

    for (int i = 0; str[i]; ++i) {
        if (str[i] != '*' && str[i] != 'X' && str[i] != '\n')
            exit(84);
        if (str[i] == '\n' && lar != count)
            exit(84);
        if (str[i] == '*' || str[i] == 'X')
            ++lar;
        else
            lar = 0;
    }
}

int solving_the_maze(char *str)
{
    int i = 0;
    int j = 0;
    int n = 0;
    char **map = my_str_to_word_array(str, "\n\0");
    solv->width = strlen(map[0]);
    for (solv->hight = 0; map[solv->hight] != NULL; ++solv->hight);
    error_handing(str);
    if (solver_maze(map, j, i, n) == 1) {
        printf("no solution found");
        exit(84);
    }
    draw_map(map);
    destroy_dante(map);
    free(str);
}

int main(int ac, char **av)
{
    struct stat s;
    char *str;
    int i = 0;
    int size = 0;
    solv = malloc(sizeof(struct maze));

    if (ac != 2 || stat(av[1], &s))
        return (84);
    str = malloc(sizeof(char) * (s.st_size + 1));
    i = open(av[1], O_RDONLY);
    if (i <= 0)
        exit(84);
    size = read(i, str, s.st_size);
    str[size] = '\0';
    if (str[0] == 'X' || str[size-1] == 'X') {
        printf("no solution found");
        exit(84);
    }
    solving_the_maze(str);
}