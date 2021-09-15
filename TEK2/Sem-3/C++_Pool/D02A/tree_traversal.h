/*
** EPITECH PROJECT, 2018
** cpp_d02a
** File description:
** ex05
*/

#ifndef TREE_TRAVERSAL_H_
# define TREE_TRAVERSAL_H_

# include "generic_list.h"

/*
** Types
*/

/* Tree */

typedef struct tree_node
{
    void                *data;
    struct tree_node    *parent;
    list_t              children;
}   tree_node_t;

typedef tree_node_t *tree_t;

/* Misc */

typedef void    (*dump_func_t)(void *data);

/* Generic Container */

typedef bool    (*push_func_t)(void *container, void *data);
typedef void*   (*pop_func_t)(void *container);

typedef struct container_s
{
    void        *container;
    push_func_t push_func;
    pop_func_t  pop_func;
}   container_t;

/*
** Functions
*/

/* Informations */

bool    tree_is_empty(tree_t tree);
void    tree_node_dump(tree_node_t *tree_node, dump_func_t dump_func);

/* Modifications */

bool            init_tree(tree_t *tree_ptr, void *data);
tree_node_t     *tree_add_child(tree_node_t *tree_node, void *data);
bool            tree_destroy(tree_t* tree_ptr);

/* Access */

void    tree_traversal(tree_t tree, container_t *container, dump_func_t dump_func);

#endif /* !TREE_TRAVERSAL_H_ */
