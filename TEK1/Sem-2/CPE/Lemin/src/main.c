/*
** EPITECH PROJECT, 2020
** lemin
** File description:
** lemin
*/

#include "../include/lib.h"
#include "../include/main.h"

int not_final(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++)
        for (int b = 0; tab[b] != NULL; b++)
            if (my_strcmp(tab[i], tab[b]) == 0 && i != b)
                return (1);
    return (0);
}

int final_ver(int i, main_t *struct_main, char **tab, char **tmp)
{
    for (int ok = 0; i < struct_main->tunels; i += 1) {
        for (int ind = 0; tab[ind] != NULL; ind++) {
            tmp = my_str_to_word_array(struct_main->map[i], '-');
            if (tmp[1] == NULL)
                return (1);
            if ((my_strcmp(tab[ind], tmp[0]) == 0)
            || ( my_strcmp(tab[ind], tmp[1]) == 0)) {
                ok += 1;
                }
        }
        if (ok == 2)
            ok = 0;
        else
            return (0);
    }
    return (not_final(tab));
}

int main(void)
{
    main_t struct_main;
    graph_t *graph = malloc(sizeof(graph_t));
    read_file(&struct_main);
    if (map_parsing(&struct_main) == 1)
        return (84);
    return (0);
}