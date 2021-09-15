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

bool double_list_add_elem_at_front(double_list_t *front_ptr, double elem)
{
    doublelist_node_t *first_node = malloc(sizeof(doublelist_node_t));

    if (first_node == NULL)
        return (false);

    first_node->value = elem;
    first_node->next = *front_ptr;
    *front_ptr = first_node;
    return (true);
}

bool double_list_add_elem_at_back(double_list_t *front_ptr, double elem)
{
    doublelist_node_t *last_node = malloc(sizeof(doublelist_node_t));
    doublelist_node_t *tmp = NULL;

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

bool double_list_add_elem_at_position(double_list_t *front_ptr, double elem, \
unsigned int position)
{
    doublelist_node_t *new_node = malloc(sizeof(doublelist_node_t));
    doublelist_node_t *tmp = NULL;
    unsigned int indx = 0;

    if (new_node == NULL)
        return (false);
    if (position == 0)
        return (double_list_add_elem_at_front(front_ptr, elem));
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