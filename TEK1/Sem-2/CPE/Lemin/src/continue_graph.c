/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** continue_graph
*/

#include "../include/lib.h"
#include "../include/main.h"

char *get_name2(char **tunels, int i)
{
    char *name = malloc(sizeof(char) * (size(tunels[i], '\0') + 1));
    int start = 0;
    int where = 0;
    for (int y = 0; tunels[i][y] != '-'; y++) {
        start += 1;
    }
    for (int y = start + 1; tunels[i][y] != '\0'; y++) {
        name[where] = tunels[i][y];
        name[where + 1] = '\0';
        where += 1;
    }
    return (name);
}

void connect_room(graph_t *graph, int y, char **tunels, int where)
{
    int pos = 0;
    int sec_pos = 0;
    int third_pos = 0;
    int fourth_pos = 0;
    char *name;
    char *out_name;

    name = get_name(tunels, where, y);
    out_name = get_name2(tunels, y);
    for (pos = 0; comp(out_name, graph[pos].name) != 0; pos++) {}
    for (sec_pos = 0; comp(name, graph[sec_pos].name) != 0; sec_pos++) {}
    for (third_pos = 0; comp(graph[sec_pos].next[third_pos].name, "stop") \
!= 0; third_pos++) {}
    graph[sec_pos].next[third_pos] = graph[pos];
    for (fourth_pos = 0; comp(graph[pos].next[fourth_pos].name, "stop") \
!= 0; fourth_pos++) {}
    graph[pos].next[fourth_pos] = graph[sec_pos];
}