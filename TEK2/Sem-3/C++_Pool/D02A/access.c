/*
** EPITECH PROJECT, 2020
** access.c
** File description:
** access
*/

#include "double_list.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

double double_list_get_elem_at_front(double_list_t list)
{
    doublelist_node_t *first_node = malloc(sizeof(doublelist_node_t));

    first_node = list;
    if (first_node == NULL)
        return (0);
    return (first_node->value);
}

double double_list_get_elem_at_back(double_list_t list)
{
    doublelist_node_t *first_node = list;

    if (first_node == NULL)
        return (0);
    while (first_node->next != NULL)
        first_node = first_node->next;
    return (first_node->value);
}

double double_list_get_elem_at_position(double_list_t list, \
unsigned int position)
{
    doublelist_node_t *tmp = list;
    unsigned int indx = 0;

    if (tmp == NULL)
        return (0);
    while (tmp->next != NULL && indx < position) {
        tmp = tmp->next;
        ++indx;
    }
    if (tmp->next == NULL && indx < position)
        return (0);
    return (tmp->value);
}

doublelist_node_t  *double_list_get_first_node_with_value(double_list_t list, \
double value)
{
    doublelist_node_t *new_node = list;

    if (new_node == NULL)
        return (NULL);
    
    while (new_node) {
        if (new_node->value == value)
            return (new_node);
        new_node = new_node->next;
    }
    return (NULL);
}