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

char *copy_string3(char *buff)
{
    char *str = malloc(sizeof(char) * 4096);
    int i = 0;
    int j = 0;

    while (buff[i] != '\n' && buff[i] != '\0') {
        str[i] = buff[i];
        ++i;
        ++j;
    }
    str[i] = '\0';
    return (str);
}

char *copy_string2(char *buff)
{
    char *str = malloc(sizeof(char) * 4096);
    int i = 0;
    int j = 0;

    if (buff[0] == ' ')
        ++i;
    while (buff[i] != '\0') {
        str[j] = buff[i];
        ++i;
        ++j;
    }
    if (buff[i-1] == ' ')
        j -= 1;
    str[j] = '\0';
    return (str);
}

void my_exit(char *str)
{
    my_printf("exit\n");
    exit(0);
}

char **reset_enviro2(char *str, char **env)
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
    for (int i = 0; env[i]; i += 1)
        if (my_strncmp(env[i], "PATH=", 5) == 0)
            envv->path = env[i];
    return (env);
}

void tcheck_error(char **tab, char **env)
{
    if (tab[1] == NULL) {
        my_printf("too few argument\n");
        envv->statuss = 1;
        envv->status2 = 1;
        display_shell(env);
    }
    if (my_strcmp(tab[1], "*") == 0) {
        env[0] = NULL;
        envv->enviro = env;
    }
    envv->statuss = 0;
    envv->status2 = 0;
}