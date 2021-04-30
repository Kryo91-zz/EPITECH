/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** minishell1
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include "../inc/my.h"

void my_exit(char *str)
{
    my_printf("exit\n");
    exit(0);
}

void reset_enviro2(char *str, char **env)
{
    char **tab = my_str_to_word_array(str, " ");
    int i = 0;

    while (env[i] != NULL)
        ++i;
    if (tab[2] == NULL)
        tab[2] = "";
    char *dest = my_strcat(my_strcat(tab[1], "="), tab[2]);
    env[i] = dest;
    env[i+1] = NULL;
    display_shell(env);
}

void tcheck_error(char **tab, char **env)
{
    if (tab[1] == NULL) {
        my_printf("too few argument\n");
        display_shell(env);
    }
    if (my_strcmp(tab[1], "*") == 0) {
        env[0] = NULL;
        display_shell(env);
    }
}