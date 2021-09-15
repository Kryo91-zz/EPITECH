/*
** EPITECH PROJECT, 2020
** generic_delete.c
** File description:
** generic
*/
#include "generic_list.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

bool list_del_elem_at_front(list_t *front_ptr)
{
    node_t *node = *front_ptr;
    node_t *tmp = NULL;

    if (node == NULL)
        return (false);
    tmp = *front_ptr;
    *front_ptr = node->next;
    free(tmp);
    return (true);
}

bool list_del_elem_at_back (list_t *front_ptr) 
{
    node_t *node = *front_ptr;
    node_t *tmp;

    if (node == NULL)
        return (false);
    while (node && node->next && node->next->next)
        node = node->next;
    if (node == NULL) {
        return (false);
    }
    tmp = node->next;
    node->next = NULL;
    free(tmp);
    return (true);
}

bool list_del_elem_at_position(list_t *front_ptr, \
unsigned int position)
{
    node_t *new_node = *front_ptr;
    node_t *tmp;

    if (!new_node)
        return (false);
    while (new_node && new_node->next != NULL && position > 0)
    {
        tmp = new_node;
        new_node = new_node->next;
        position -= 1;
    }
    tmp->next = new_node->next;
    return (true);
}