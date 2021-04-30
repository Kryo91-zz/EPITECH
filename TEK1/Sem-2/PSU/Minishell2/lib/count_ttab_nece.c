/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** redir.c
*/

#include "../inc/my.h"

int count_tab(char **tab, char *sep, int i)
{
    int count = 0;

    for (; tab[i]; i += 2) {
        if (my_strcmp(tab[i], sep) == 0)
            ++count;
        else {
            if (my_strcmp(tab[i], ">") == 0)
                envv->vercrocd = 1;
            if (my_strcmp(tab[i], ">>") == 0)
                envv->vercrocdd = 1;
            return (count);
        }
    }
    return (count);
}

char ***get_tab(char **cmds_list, char ***tab, int i)
{
    tab = malloc(sizeof(char **) * (envv->countp + 2));
    int j = 0;

    for (;cmds_list[i] && my_strcmp(cmds_list[i], "|") == 0; i += 2) {
        tab[j] = malloc(sizeof(char *) * 4096);
        tab[j] = my_str_to_word_array(cmds_list[i-1], "");
        ++j;
    }
    tab[j] = malloc(sizeof(char *) * 4096);
    tab[j] = my_str_to_word_array(cmds_list[i-1], "");
    tab[j+1] = NULL;
    return (tab);
}