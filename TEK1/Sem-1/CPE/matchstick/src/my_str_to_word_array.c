/*
** EPITECH PROJECT, 2019
** error
** File description:
** Str to word array
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

int my_delim(char s, char *lim)
{
    int   i = 0;

    while (lim[i]) {
        if (s == lim[i])
            return (-1);
        i++;
    }
    return (0);
}

int	while_delim(char const *str, int i, char *lim)
{
    if (my_delim(str[i], lim) == -1) {
        while (my_delim(str[i], lim) == -1)
            i++;
        i -= 1;
    }
    return (i);
}

int     count_word(char const *str, char *lim)
{
    int     i = 0;
    int	res = 1;

    while (str[i]) {
        i = while_delim(str, i, lim);
        res += 1;
        i++;
    }
    return (res);
}

int word_size(char *str, int i, char *lim)
{
    int	len = 0;

    while (my_delim(str[i], lim) == 0 && str[i]) {
        len++;
        i++;
    }
    return (len);
}

char    **my_str_to_word_array(char *str, char *lim)
{
    int nb_word = count_word(str, lim) + 2;
    int i = 0;
    char    **tab;
    int y = 0;
    int x = 0;

    tab = malloc(sizeof(char *) * nb_word + 1);
    while (str[i]) {
        x = 0;
        for (i = i; (my_delim(str[i], lim) == -1 && str[i]); i++);
        tab[y] = malloc(sizeof(char) * (word_size(str, i, lim) + 1));
        for (i = i; my_delim(str[i], lim) == 0 && str[i]; i++ , x++)
            tab[y][x] = str[i];
        tab[y][x] = '\0';
        y++;
        for (i = i; (my_delim(str[i], lim) == -1 && str[i]); i++);
    }
    tab[y] = NULL;
    return (tab);
    free(tab);
}