/*
** EPITECH PROJECT, 2020
** generique_information.c
** File description:
** information
*/

#include "generic_list.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

unsigned int list_get_size(list_t list)
{
    int size = 0;
    node_t *node = list;

    while (node) {
        ++size;
        node = node->next;
    }
    return (size);
}

bool list_is_empty(list_t list)
{
    node_t *node = list;

    if (node == NULL)
        return (true);
    else
        return (false);
}

void list_dump(list_t list , value_displayer_t val_disp)
{
    node_t *node = list;

    while (node) {
        val_disp(node->value);
        node = node->next;
    }
}