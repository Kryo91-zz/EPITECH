/*
** EPITECH PROJECT, 2019
** error
** File description:
** Str to word array
*/

#include <unistd.h>
#include <stdlib.h>
#include "../inc/my.h"

int my_pipes(char s, char *lim)
{
    int   i = 0;

    while (lim[i]) {
        if (s == lim[i])
            return (-1);
        i++;
    }
    return (0);
}

int	while_pipes(char const *str, int i, char *lim)
{
    if (my_pipes(str[i], lim) == -1) {
        while (my_pipes(str[i], lim) == -1)
            i++;
        i -= 1;
    }
    return (i);
}

int     count_pipes(char const *str, char *lim)
{
    int     i = 0;
    int	res = 1;

    while (str[i]) {
        i = while_pipes(str, i, lim);
        res += 1;
        i++;
    }
    return (res);
}

int unpipes_size(char *str, int i, char *lim)
{
    int	len = 0;

    while (my_pipes(str[i], lim) == 0 && str[i]) {
        len++;
        i++;
    }
    return (len);
}

char    **my_str_to_word_array_piper(char *str, char *lim)
{
    int nb_word = count_pipes(str, lim) + 2;
    int i = 0, y = 0, x = 0;
    char    **tab = malloc(sizeof(char *) * nb_word + 1);

    for (;str[i]; ++y, x = 0) {
        for (i = i; (my_pipes(str[i], lim) == -1 && str[i]); i++);
        tab[y] = malloc(sizeof(char) * (unpipes_size(str, i, lim) + 1));
        for (i = i; my_pipes(str[i], lim) == 0 && str[i]; i++ , x++) {
            tab[y][x] = str[i];
            if (str[i+1] && my_pipes(str[i+1], lim) == -1 && str[i+2] && \
my_pipes(str[i+2], lim) == 0) {
                tab[y][x+1] = str[i+1];
                x += 1;
                i += 1;
            }
        }
        tab[y][x] = '\0';
    }
    tab[y] = NULL;
    return (tab);
}