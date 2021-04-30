/*
** EPITECH PROJECT, 2020
** all lib
** File description:
** include aml lib
*/

#ifndef MAIN_H_
#define MAIN_H_

#include "lib.h"

typedef struct main_s
{
    int ant;
    int tunels;
    char **map;
    char *input;
}main_t;

typedef struct graph_s
{
    char *name;
    int tunels;
    struct graph_s *next;
}graph_t;

int my_strcmp(char const *s1, char const *s2);
int final_ver(int i, main_t *struct_main, char **tab, char **tmp);
int error2(main_t *my_struct);
int map_parsing(main_t *struct_main);
void read_file(main_t *my_struct);
int comp(char *str1, char *str2);
int size(char *str, char c);
void cpy(char *str, char *cpy);
graph_t *init_graph(main_t *m_struct, graph_t *graph);
void create_graph(char **tunels, int where, graph_t *graph);
char *get_name2(char **tunels, int i);
void connect_room(graph_t *graph, int y, char **tunels, int where);
int get_start(main_t *m_struct);
char *get_name(char **tunels, int where, int i);
int error(main_t *my_struct);
int    my_getnbr(char const *str);
int my_compute_power_rec(int nb, int p);

#endif /* !MAIN_H_ */
