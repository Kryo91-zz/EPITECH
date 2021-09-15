/*
** EPITECH PROJECT, 2018
** cpp_d02a
** File description:
** ex04
*/

#ifndef MAP_H_
# define MAP_H_

#include "generic_list.h"

/* Types */

typedef struct pair
{
    void    *key;
    void    *value;
}   pair_t;

typedef list_t map_t;

typedef int (*key_comparator_t)(void *first_key, void *second_key);

/* Informations */

unsigned int    map_get_size(map_t map);
bool            map_is_empty(map_t map);

/* Internals */

key_comparator_t    key_cmp_container(bool   store, key_comparator_t new_key_cmp);
int                 pair_comparator(void *first, void *second);

/* Modification */

bool    map_add_elem(map_t *map_ptr, void *key, void *value, key_comparator_t key_cmp);
bool    map_del_elem(map_t *map_ptr, void *key, key_comparator_t key_cmp);

/* Access */

void    *map_get_elem(map_t map, void *key, key_comparator_t key_cmp);

#endif /* !MAP_H_ */
