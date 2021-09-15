/*
** EPITECH PROJECT, 2020
** modification.c
** File description:
** modification
*/
#include "double_list.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

bool double_list_del_elem_at_front(double_list_t *front_ptr)
{
    doublelist_node_t *node = *front_ptr;
    doublelist_node_t *tmp = NULL;

    if (node == NULL)
        return (false);
    tmp = *front_ptr;
    *front_ptr = node->next;
    free(tmp);
    return (true);
}

bool double_list_del_elem_at_back (double_list_t *front_ptr) 
{
    doublelist_node_t *node = *front_ptr;
    doublelist_node_t *tmp;

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

bool double_list_del_elem_at_position(double_list_t *front_ptr, \
unsigned int position)
{
    doublelist_node_t *new_node = *front_ptr;
    doublelist_node_t *tmp;

    if (!new_node)
        return (false);
    if (position == 0)
        return (double_list_del_elem_at_front(front_ptr));
    while (new_node && new_node->next != NULL && position > 0)
    {
        tmp = new_node;
        new_node = new_node->next;
        position -= 1;
    }
    tmp->next = new_node->next;
    return (true);
}