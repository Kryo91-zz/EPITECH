/*
** EPITECH PROJECT, 2019
** asm
** File description:
** slice.c
*/

#include <stdlib.h>
#include <unistd.h>

void set_buff(void *buff, int fill, size_t nb_bytes);

size_t my_strlen(const char *str);

size_t array_len(void *array);

// str[start] is included, str[end] is not

char *str_slice(const char *str, const size_t start, const size_t end)
{
    char *slice = NULL;
    int idx = 0;

    if (start > end)
        return (NULL);
    slice = malloc(sizeof(char) * (end - start + 1));
    set_buff(slice, 0, (end - start + 1) * sizeof(char));
    if (start >= my_strlen(str))
        return (slice);
    for (int i = start; str[i] && i < end; idx++)
        slice[idx] = str[i++];
    return (slice);
}

// tab[start] is included, tab[end] is not

void *tab_slice(void *tab, const size_t  start, const size_t  end)
{
    void **array = tab;
    void **slice = malloc(sizeof(void *) * (end - start + 1));
    int idx = 0;

    set_buff(slice, 0, (end - start + 1) * sizeof(void *));
    if (start >= array_len(array))
        return (slice);
    for (int i = start; array[i] && i < end; idx++)
        slice[idx] = array[i++];
    return (slice);
}