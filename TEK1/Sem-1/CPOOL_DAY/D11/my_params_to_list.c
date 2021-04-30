/*
** EPITECH PROJECT, 2019
** MY_PARAMS_TO_LIST
** File description:
** .C
*/

#include <stdlib.h>
#include "mylist.h"


int my_list(linked_list_t **list, char *data)
{
	linked_list_t *elem;
	
	elem = malloc(sizeof(*elem));
	if (elem == NULL)
		return (1);
        elem->data = data;
        elem->next = *list;
        *list = elem;
        return(0);

}

linked_list_t *my_params_to_list(int ac, char * const *av)
{
    int i = 0;
    linked_list_t *list = NULL;

    for (; i <= ac -1; i++) {
        my_list(&list, av[i]);
    }
    return (list);
}

    
