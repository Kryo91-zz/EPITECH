/*
** EPITECH PROJECT, 2019
** error
** File description:
** Str to word array
*/

#include <unistd.h>
#include <stdlib.h>

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

int count_words(char *str, char sep)
{
    int lock = 0;
    int nb_words = 1;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == sep && lock == 0) {
            nb_words += 1;
            lock = 1;
        }
        if (str[i] != sep)
            lock = 0;
    }
    return (nb_words);
}

int count_letters(char *str, int pos, char sep)
{
    int nb_letters = 0;

    for (; str[pos] != sep && str[pos] != '\0'; pos++)
        nb_letters += 1;
    return (nb_letters);
}

char **my_str_to_word_array(char *str, char sep)
{
    int i = 0;
    int j = 0;
    int pos = 0;
    int nb_words = count_words(str, sep);
    char **tab = malloc(sizeof(char *) * (nb_words + 1));

    while (str[pos]) {
        if (str[pos] != sep) {
            tab[i] = malloc(sizeof(char) * \
            (count_letters(str, pos, sep) + 1));
            for (; str[pos] != sep && str[pos] != '\0'; pos++, j++)
                tab[i][j] = str[pos];
            tab[i][j] = '\0';
            j = 0;
            i++;
        } else
            pos++;
    }
    tab[i] = NULL;
    return (tab);
}