/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** create_graph
*/

#include "../include/lib.h"
#include "../include/main.h"

char *get_name(char **tunels, int where, int i)
{
    char *name = malloc(sizeof(char) * (size(tunels[i], '-') + 1));
        for (int y = 0; tunels[i][y] != '-'; y++) {
            name[y] = tunels[i][y];
            name[y + 1] = '\0';
        }
    return (name);
}

void replace(graph_t *graph, char *name)
{
    int stop = 0;
    for (int y = 0; stop == 0; y++) {
        if (comp("stop", graph[y].name) == 0) {
            graph[y].name = malloc(sizeof(char) * (size(name, '\0') + 1));
            cpy(name, graph[y].name);
            graph[y].tunels += 1;
            stop = 1;
        } else if (comp(name, graph[y].name) == 0) {
            graph[y].tunels += 1;
            stop = 1;
        }
    }
}

void outpout_malloc(graph_t *graph)
{
    for (int i = 0; comp("stop", graph[i].name) != 0; i++) {
        graph[i].next = malloc(sizeof(graph_t) * (graph[i].tunels + 1));
        for (int y = 0; y < graph[i].tunels + 1; y++) {
            graph[i].next[y].name = malloc(sizeof(char) * 5);
            cpy("stop", graph[i].next[y].name);
        }
    }
}

void create_graph(char **tunels, int where, graph_t *graph)
{
    int pos = 0;
    int s_name = 0;
    char *name;
    char *out_name;

    for (int i = 0; i < where; i++) {
        graph[i].name = malloc(sizeof(char) * 5);
        graph[i].tunels = 0;
        cpy("stop", graph[i].name);
    }
    for (int i = 0; i < where; i++) {
        name = get_name(tunels, where, i);
        replace(graph, name);
        out_name = get_name2(tunels, i);
        replace(graph, out_name);
        outpout_malloc(graph);
    }
    for (int i = 0; i < where; i++) {
        connect_room(graph, i, tunels, where);
    }
}

int get_start(main_t *m_struct)
{
    int nb = 0;
    int where = 0;

    for (int i = 0; i < m_struct->tunels; i++) {
        for (int y = 0; m_struct->map[i][y] != '\0'; y++) {
            if (m_struct->map[i][y] == '-' && where == 0) {
                where = i;
                break;
            }
        }
    }
    return (where);
}