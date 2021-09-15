/*
** EPITECH PROJECT, 2020
** generic_access.c
** File description:
** access
*/

#include "generic_list.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void *list_get_elem_at_front(list_t list)
{
    node_t *first_node = malloc(sizeof(node_t));

    first_node = list;
    if (first_node == NULL)
        return (0);
    return (first_node->value);
}

void *list_get_elem_at_back(list_t list)
{
    node_t *first_node = list;

    if (first_node == NULL)
        return (0);
    while (first_node->next != NULL)
        first_node = first_node->next;
    return (first_node->value);
}

void *list_get_elem_at_position(list_t list, \
unsigned int position)
{
    node_t *tmp = list;
    unsigned int indx = 0;

    if (tmp == NULL)
        return (0);
    while (tmp->next != NULL && indx < position - 1) {
        tmp = tmp->next;
        ++indx;
    }
    if (tmp->next == NULL && indx < position - 1)
        return (0);
    return (tmp->value);
}

void list_clear(list_t *front)
{
    *front = NULL;
}