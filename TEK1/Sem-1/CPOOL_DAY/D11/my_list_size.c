/*
** EPITECH PROJECT, 2019
** MY_LIST_SIZE
** File description:
** .c
*/

#include "mylist.h"
#include "my.h"

int my_list_size(linked_list_t const *begin)
{
    int size = 0;
    linked_list_t const *temp;

    temp = begin;
    while (temp != NULL) {
        size++;
        temp = temp->next;
    }
    return(size);
}
