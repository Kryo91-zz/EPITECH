/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** graph
*/

#include "../include/lib.h"
#include "../include/main.h"

int comp(char *str1, char *str2)
{
    int outpout = 0;

    for (int i = 0; str1[i] != '\0' && str2[i] != '\0'; i++) {
        if (str1[i] != str2[i])
            outpout = 1;
    }
    return (outpout);
}

int size(char *str, char c)
{
    int size = 0;
    for (int i = 0; str[i] != c; i++) {
        size += 1;
    }
    return (size);
}

void cpy(char *str, char *cpy)
{
    for (int i = 0; str[i] != '\0'; i++) {
        cpy[i] = str[i];
        cpy[i + 1] = '\0';
    }
}

int fill_tab(main_t *m_struct, char **tab, int start)
{
    int where = 0;
    int stop = 0;

    for (int i = start; i < m_struct->tunels; i++) {
        while (m_struct->map[i][0] == '#')
            i += 1;
        for (int y = 0; m_struct->map[i][y] != '\0'; y++) {
            tab[where][y] = m_struct->map[i][y];
            tab[where][y + 1] = '\0';
        }
        where += 1;
    }
    tab[where] = malloc(sizeof(char) * 6);
    cpy("#stop\0", tab[where]);
    return (where);
}

graph_t *init_graph(main_t *m_struct, graph_t *graph)
{
    int nb_start = 0;
    char **tunels;
    int where = 0;

    tunels = malloc(sizeof(char *) * m_struct->tunels);
    for (int i = nb_start; i < m_struct->tunels; i++) {
        tunels[where] = malloc(sizeof(char) * \
(size(m_struct->map[i], '\0') + 2));
        where += 1;
    }
    nb_start = get_start(m_struct);
    where = fill_tab(m_struct, tunels, nb_start);
    graph = malloc(sizeof(graph_t) * where);
    create_graph(tunels, where, graph);
    return (graph);
}