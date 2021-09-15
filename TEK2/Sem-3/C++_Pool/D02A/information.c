/*
** EPITECH PROJECT, 2020
** information.c
** File description:
** information
*/

#include "double_list.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

unsigned int double_list_get_size(double_list_t list)
{
    int size = 0;
    doublelist_node_t *node = list;

    while (node) {
        ++size;
        node = node->next;
    }
    return (size);
}

bool double_list_is_empty(double_list_t list)
{
    doublelist_node_t *node = list;

    if (node == NULL)
        return (true);
    else
        return (false);
}

void double_list_dump(double_list_t list)
{
    doublelist_node_t *node = list;

    while (node) {
        printf("%f\n", node->value);
        node = node->next;
    }
}