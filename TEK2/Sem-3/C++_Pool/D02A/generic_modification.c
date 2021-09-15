/*
** EPITECH PROJECT, 2020
** generic_modification.c
** File description:
** modification
*/

#include "generic_list.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

bool list_add_elem_at_front(list_t *front_ptr, void *elem)
{
    node_t *first_node = malloc(sizeof(node_t));

    if (first_node == NULL)
        return (false);

    first_node->value = elem;
    first_node->next = *front_ptr;
    *front_ptr = first_node;
    return (true);
}

bool list_add_elem_at_back(list_t *front_ptr, void *elem)
{
    node_t *last_node = malloc(sizeof(node_t));
    node_t *tmp = NULL;

    if (last_node == NULL)
        return (false);
    last_node->value = elem;
    last_node->next = NULL;
    tmp = *front_ptr;
    while (tmp != NULL && tmp->next != NULL)
        tmp = tmp->next;
    if (tmp == NULL) {
        *front_ptr = last_node;
        return (true);
    }
    tmp->next = last_node;
    return (true);
}

bool list_add_elem_at_position(list_t *front_ptr, void *elem, \
unsigned int position)
{
    node_t *new_node = malloc(sizeof(node_t));
    node_t *tmp = NULL;
    unsigned int indx = 0;

    if (new_node == NULL)
        return (false);
    new_node->value = elem;
    tmp = *front_ptr;
    while (tmp->next != NULL && indx < position - 1) {
        tmp = tmp->next;
        ++indx;
    }
    if (tmp->next == NULL && indx < position - 1)
        return (false);
    new_node->next = tmp->next;
    tmp->next = new_node;
    return (true);
}