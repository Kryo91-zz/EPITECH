/*
** EPITECH PROJECT, 2019
** bootstrap_world
** File description:
** my_append_str.c
*/

#include "../../include/my.h"

char *my_append_str(char *str, char c)
{
    size_t len = my_strlen(str);
    char *tmp = malloc(sizeof(char) * (len + 2));

    if (!tmp)
        return (NULL);
    for (int i = 0; str[i]; i++)
        tmp[i] = str[i];
    tmp[len] = c;
    tmp[len + 1] = 0;
    free(str);
    return (tmp);
}

void *append_array(void *arr, void *to_append)
{
    void **array = (void **)arr;
    size_t len = array_len(array);
    void **tmp = malloc(sizeof(void *) * (len + 2));

    if (!tmp)
        return (NULL);
    for (int i = 0; array[i]; i++)
        tmp[i] = array[i];
    tmp[len] = to_append;
    tmp[len + 1] = 0;
    free(arr);
    return (tmp);
}