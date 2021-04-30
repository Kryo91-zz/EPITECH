/*
** EPITECH PROJECT, 2019
** lib
** File description:
** array_handling.c
*/

#include "../../include/my.h"
#include <unistd.h>
#include <stdlib.h>

char *my_append(char *str, char c)
{
    size_t len = my_strlen(str);
    char *tmp = malloc(sizeof(char) * (len + 2));

    for (int i = 0; str[i]; i++)
        tmp[i] = str[i];
    tmp[len] = c;
    tmp[len + 1] = 0;
    free(str);
    return (tmp);
}

char *my_append_word(char *tmp, int *i, char *src)
{
    char *word = malloc(sizeof(char));
    char end = 0;

    word[0] = 0;
    if (src[*i] != '\"' && src[*i] != '\'') {
        free(word);
        return (my_append(tmp, src[*i]));
    }
    end = src[*i];
    *i += 1;
    for (; src[*i] != end; *i += 1)
        word = my_append(word, src[*i]);
    *i += 1;
    return (my_strcat(tmp, word));
}

char **my_append_array(char **array, char *str)
{
    size_t len = 0;
    char **tmp = NULL;

    if (!str || !str[0] || str[0] == '\n')
        return (array);
    for (; array[len]; len++);
    tmp = malloc(sizeof(char *) * (len + 2));
    for (int i = 0; array[i]; i++)
        tmp[i] = array[i];
    tmp[len] = str;
    tmp[len + 1] = NULL;
    return (tmp);
}

char **my_word_array(char *st)
{
    char *tmp = malloc(sizeof(char));
    char **array = malloc(sizeof(char *));

    tmp[0] = 0;
    array[0] = NULL;
    if (!st || st[0] == 0 || !(str_is_blank(st)))
        return (NULL);
    for (int i = 0; st[i]; i++) {
        for (; st[i] && st[i] != '\n' && st[i] != ' ' && st[i] != '\t'; i++)
            tmp = my_append_word(tmp, &i, st);
        if (i <= 0)
            continue;
        if (!st[i])
            i--;
        array = my_append_array(array, tmp);
        tmp = malloc(sizeof(char));
        tmp[0] = 0;
    }
    return (array);
}

char **my_sep_array(char *st, char sep)
{
    char *tmp = malloc(sizeof(char));
    char **array = malloc(sizeof(char *));

    tmp[0] = 0;
    array[0] = NULL;
    if (!st || st[0] == 0 || !(str_is_blank(st)))
        return (NULL);
    for (int i = 0; st[i]; i++) {
        for (; st[i] && st[i] != sep; i++)
            tmp = my_append(tmp, st[i]);
        if (i <= 0)
            continue;
        if (!st[i])
            i--;
        array = my_append_array(array, tmp);
        tmp = malloc(sizeof(char));
        tmp[0] = 0;
    }
    return (array);
}