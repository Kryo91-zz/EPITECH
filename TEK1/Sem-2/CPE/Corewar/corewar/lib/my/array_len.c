/*
** EPITECH PROJECT, 2019
** bootstrap_world
** File description:
** array_len.c
*/

#include <stdlib.h>

/*
Send a NULL terminated pointer table/array
it will be browsed through and its size will be returned
*/

size_t array_len(void *array)
{
    size_t len = 0;
    void **arithmetic_array = (void **)array;

    if (!arithmetic_array)
        return (0);
    while (arithmetic_array[len])
        len++;
    return (len);
}
